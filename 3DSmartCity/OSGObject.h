#pragma once

#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osgViewer\api\Win32/GraphicsWindowWin32>
#include <osgGA/TrackballManipulator>
#include <osgEarth/MapNode>
#include <osgEarthUtil/EarthManipulator>
#include <osgEarthUtil/Sky>
#include <osgEarth/ImageLayer>
using namespace std;
class COSGObject
{
public:
	COSGObject(HWND hWnd);
	~COSGObject(void);
	void InitOSG();
	void InitSceneGraph();
	void InitCameraConfig();//初始化相机
	void PreFrameUpdate();//前处理
	void PostFrameUpdate();//后处理
	static void Render(void * ptr);//规避线程互斥方法
	osg::ref_ptr<osgEarth::MapNode> mapNode;
	vector<string> layernames;
	osgEarth::ImageLayerVector imageLayerVec;

	osgViewer::Viewer *getViewer();
	void InitOsgEarth();
	void setChinaBoundariesOpacity(double opt);
	double getChinaBoundariesOpacity();
	void rmvChinaBounds();
	void addChinaBounds();

private:
	HWND n_hWnd;//创建一个句柄
	osgViewer::Viewer * mViewer;
	osg::ref_ptr<osg::Group> mRoot;

	osg::ref_ptr<osgEarth::Util::EarthManipulator> em;
	osg::ref_ptr<osgEarth::ImageLayer> china_boundaries;

};


