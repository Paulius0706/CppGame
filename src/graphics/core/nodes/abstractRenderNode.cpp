#ifndef AbstractRenderNode_CPP
#define AbstractRenderNode_CPP

#include <vector>
#include <functional>
#include <memory>



class AbstractRenderNode
{
public:
    template <typename T>
    class NodeInterface {
    public:
        NodeInterface(std::shared_ptr<T> object) : object(object) {}
        void render() const { object->render(); }
    private:
        std::shared_ptr<T> object;
    };
protected:
    std::vector<AbstractRenderNode*> children;
    AbstractRenderNode(): children(std::vector<AbstractRenderNode*>()){
    }
    virtual void render(){
        for(std::vector<AbstractRenderNode*>::iterator it = children.begin(); it != children.end(); it++){
            (*it)->render();
        }
    }
    virtual void load(){
        
    }
};



#endif