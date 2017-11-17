#include <osgViewer/Viewer>
#include "Camera"

HUDCamera::HUDCamera( double left, double right, double bottom, double top )
{
	setReferenceFrame( osg::Transform::ABSOLUTE_RF );
	setClearMask( GL_DEPTH_BUFFER_BIT );
	setRenderOrder( osg::Camera::POST_RENDER );
	setAllowEventFocus( false );
	setProjectionMatrix( osg::Matrix::ortho2D(left, right, bottom, top) );
	getOrCreateStateSet()->setMode( GL_LIGHTING, osg::StateAttribute::OFF );
}
