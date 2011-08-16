package com.helloftgles;


import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.app.Activity;
import android.content.Context;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.view.MotionEvent;

public class HelloFTGLESActivity extends Activity {
    /** Called when the activity is first created. */
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mGLView = new DemoGLSurfaceView(this);
        setContentView(mGLView);
    }

    @Override
    protected void onPause() {
        super.onPause();
        mGLView.onPause();
    }

    @Override
    protected void onResume() {
        super.onResume();
        mGLView.onResume();
    }

    private GLSurfaceView mGLView;

    static {
    	System.loadLibrary("stlport");
    	//System.loadLibrary("freetype2");
    	try
    	{
    		//System.loadLibrary("ftgles");
    	}
    	catch (UnsatisfiedLinkError e)
    	{
    		
    	System.out.println(e.getMessage());
    	}
    	System.loadLibrary("helloftgles");
    }
}

class DemoGLSurfaceView extends GLSurfaceView {
public DemoGLSurfaceView(Context context) {
    super(context);
    mRenderer = new DemoRenderer();
    setRenderer(mRenderer);
}

public boolean onTouchEvent(final MotionEvent event) {
    if (event.getAction() == MotionEvent.ACTION_DOWN) {
        nativePause();
    }
    return true;
}

DemoRenderer mRenderer;

private static native void nativePause();
}

class DemoRenderer implements GLSurfaceView.Renderer {
public void onSurfaceCreated(GL10 gl, EGLConfig config) {
    nativeInit();
}

public void onSurfaceChanged(GL10 gl, int w, int h) {
    //gl.glViewport(0, 0, w, h);
    nativeResize(w, h);
}

public void onDrawFrame(GL10 gl) {
    nativeRender();
}

private static native void nativeInit();
private static native void nativeResize(int w, int h);
private static native void nativeRender();
private static native void nativeDone();
}