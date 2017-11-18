#include <osg/NodeVisitor>
#include <osg/Node>

#include "FindNamedNode.hpp"

FindNamedNode::FindNamedNode( const std::string& name )
      : osg::NodeVisitor( osg::NodeVisitor::TRAVERSE_ALL_CHILDREN ),
        _name( name ) {}

void FindNamedNode::apply( osg::Node& node )
{
	if (node.getName() == _name)
		_node = &node;
	traverse( node );
}

osg::Node* FindNamedNode::getNode() { return _node.get(); }

