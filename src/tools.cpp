/* Caml headers */
extern "C" {
#include<caml/mlvalues.h>
#include<caml/memory.h>
#include<caml/callback.h>
#include<caml/fail.h>
#include<caml/alloc.h>
#include<caml/misc.h>
}

#include <OgreRoot.h>
#include <OgreCamera.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>

void demo() {
  Ogre::Root *mRoot;
  Ogre::Camera* mCamera;
  Ogre::SceneManager* mSceneMgr;
  Ogre::RenderWindow* mWindow;
  mRoot = new Ogre::Root("", "", "LowLevelOgre.log");
  Ogre::StringVector required_plugins;
  required_plugins.push_back("GL RenderSystem");
  required_plugins.push_back("Octree & Terrain Scene Manager");
 
  Ogre::StringVector plugins_toLoad;
  plugins_toLoad.push_back("RenderSystem_GL");
  plugins_toLoad.push_back("Plugin_OctreeSceneManager");
  

  printf("What ??\n");
}

extern "C" {
  value ogrillon_demo(value unit) {
    demo();
    return Val_unit;
  }
}
