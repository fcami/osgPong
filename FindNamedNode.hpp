#include <osg/NodeVisitor>
#include <osg/Node>

// Visitor Pattern as in GoF / Gamma95
// TODO: a better implementation would build/return a list

class FindNamedNode : public osg::NodeVisitor
{
public:
    FindNamedNode( const std::string& name );
	
	// find the named node and save its address in _node
    virtual void apply( osg::Node& node );

	// accessor to _node
    osg::Node* getNode();

protected:
    std::string _name;
    osg::ref_ptr<osg::Node> _node;
};

