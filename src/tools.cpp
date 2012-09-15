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
#include <OgreLogManager.h>
#include <OgreViewport.h>
#include <OgreEntity.h>
#include <OgreWindowEventUtilities.h>
#include <OgrePlugin.h>
#include <OgreRenderSystem.h>

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
  for (Ogre::StringVector::iterator j = plugins_toLoad.begin(); j != plugins_toLoad.end(); j++)
    {
      mRoot->loadPlugin(*j);
    }
 
  // Check if the required plugins are installed and ready for use
  // If not: exit the application
  Ogre::Root::PluginInstanceList ip = mRoot->getInstalledPlugins();
  for (Ogre::StringVector::iterator j = required_plugins.begin(); j != required_plugins.end(); j++)
    {
      bool found = false;
      // try to find the required plugin in the current installed plugins
      for (Ogre::Root::PluginInstanceList::iterator k = ip.begin(); k != ip.end(); k++)
        {
	  if ((*k)->getName() == *j)
            {
	      found = true;
	      break;
            }
        }
      if (!found)  // return false because a required plugin is not available
        {
	  exit(42);
        }
    }
  
  //-------------------------------------------------------------------------------------
  // setup resources
  // Only add the minimally required resource locations to load up the Ogre head mesh
  Ogre::ResourceGroupManager::getSingleton().addResourceLocation("../../media/materials/programs", "FileSystem", "General");
  Ogre::ResourceGroupManager::getSingleton().addResourceLocation("../../media/materials/scripts", "FileSystem", "General");
  Ogre::ResourceGroupManager::getSingleton().addResourceLocation("../../media/materials/textures", "FileSystem", "General");
  Ogre::ResourceGroupManager::getSingleton().addResourceLocation("../../media/models", "FileSystem", "General");
  
  //-------------------------------------------------------------------------------------
  // configure
  // Grab the OpenGL RenderSystem, or exit
  Ogre::RenderSystem* rs = mRoot->getRenderSystemByName("OpenGL Rendering Subsystem");
  if(!(rs->getName() == "OpenGL Rendering Subsystem"))
    {
      exit(42);
    }
  // configure our RenderSystem
  rs->setConfigOption("Full Screen", "No");
  rs->setConfigOption("VSync", "No");
  rs->setConfigOption("Video Mode", "800 x 600 @ 32-bit");
  
  mRoot->setRenderSystem(rs);
  
  mWindow = mRoot->initialise(true, "LowLevelOgre Render Window");
  //-------------------------------------------------------------------------------------
  // choose scenemanager
  // Get the SceneManager, in this case the OctreeSceneManager
  mSceneMgr = mRoot->createSceneManager("OctreeSceneManager", "DefaultSceneManager");
  //-------------------------------------------------------------------------------------
  // create camera
  // Create the camera
  mCamera = mSceneMgr->createCamera("PlayerCam");
  
  // Position it at 500 in Z direction
  mCamera->setPosition(Ogre::Vector3(0,0,80));
  // Look back along -Z
  mCamera->lookAt(Ogre::Vector3(0,0,-300));
  mCamera->setNearClipDistance(5);
  
  //-------------------------------------------------------------------------------------
  // create viewports
  // Create one viewport, entire window
  Ogre::Viewport* vp = mWindow->addViewport(mCamera);
  vp->setBackgroundColour(Ogre::ColourValue(0,0,0));
  
  // Alter the camera aspect ratio to match the viewport
  mCamera->setAspectRatio(Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));
  //-------------------------------------------------------------------------------------
  // Set default mipmap level (NB some APIs ignore this)
  Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);
  //-------------------------------------------------------------------------------------
  // Create any resource listeners (for loading screens)
  //createResourceListener();
  //-------------------------------------------------------------------------------------
  // load resources
  Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
  //-------------------------------------------------------------------------------------
  // Create the scene
  Ogre::Entity* ogreHead = mSceneMgr->createEntity("Head", "ogrehead.mesh");
  
  Ogre::SceneNode* headNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
  headNode->attachObject(ogreHead);
  
  // Set ambient light
  mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));
  
  // Create a light
  Ogre::Light* l = mSceneMgr->createLight("MainLight");
  l->setPosition(20,80,50);
  //-------------------------------------------------------------------------------------
  
  //mRoot->startRendering();
  while(true)
    {
      // Pump window messages for nice behaviour
      Ogre::WindowEventUtilities::messagePump();
      
      // Render a frame
      mRoot->renderOneFrame();
      
      if(mWindow->isClosed())
        {
	  exit(42);
        }
    }
  printf("What ??\n");
}

extern "C" {
  value ogrillon_demo(value unit) {
    demo();
    return Val_unit;
  }
}
