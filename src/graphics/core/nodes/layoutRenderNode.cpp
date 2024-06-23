#ifndef LayoutRenderNode_CPP
#define LayoutRenderNode_CPP

#include <glad/glad.h>
#include <string>
#include <sstream>
#include <map>
#include <mutex>
#include <iterator>
#include "../layout.cpp"
#include "../shader.cpp"
#include "abstractRenderNode.cpp"
#include "../uniformObject.cpp"

template <class T>
class LayoutRenderNode : public AbstractRenderNode
{
private:
    static std::string ToString(size_t sz) {
        char buf[24]; // just big enough
        sprintf(buf,"%u",sz);
        std::string s = buf;
        return buf;

    }
protected:
    Layout<T>* layout;
    std::unique_ptr<std::mutex> m_mutex;
    std::map<std::string,UniformObject*> uniformObjects; 
    LayoutRenderNode() : AbstractRenderNode(), 
        uniformObjects(std::map<std::string,UniformObject*>()), 
        //layout(Layout<T>(nullptr,nullptr,0,nullptr,0)),
        m_mutex(std::make_unique<std::mutex>()){
    }
    void render() override{
        m_mutex->lock();
        try{
            layout->use();
            for (std::map<std::string,UniformObject*>::iterator it = uniformObjects.begin(); it != uniformObjects.end(); it++)
            {
                //UniformObject** key = it->first;
                UniformObject* value = it->second;
                if(value ->visible){
                    value->loadUniforms();
                    layout->render();
                }
            }
            layout->unuse();
        }
        catch(...){

        }
        m_mutex->unlock();
    }
    void load() override{

    }

    
public:
    bool addUniformObject(UniformObject* uniformObject){
        bool result = true;
        m_mutex->lock();
        try{
            std::string key = ToString(reinterpret_cast<size_t>(uniformObject));
            uniformObjects[key] = uniformObject;
        }
        catch(...){
            result = false;
        }
        m_mutex->unlock();
        return result;
    }
    bool removeUniformObject(UniformObject* uniformObject){
        bool result = true;
        m_mutex->lock();
        try{
            std::string key = ToString(reinterpret_cast<size_t>(uniformObject));
            uniformObjects.erase(key);
        }
        catch(...){
            result = false;
        }
        m_mutex->unlock();
        return result;
    }
};
#endif