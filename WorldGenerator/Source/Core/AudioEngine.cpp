//
//  AudioEngine.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 17/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "AudioEngine.hpp"
#include <iostream>

AudioEngine::AudioEngine () {
    device = alcOpenDevice(NULL);
    if (device == NULL) std::cout << "ERROR: Failed to init OpenAL" << std::endl;
    
    //Create a context
    context = alcCreateContext(device,NULL);
    
    //Set active context
    alcMakeContextCurrent(context);
    
    // Clear Error Code
    alGetError();
}

AudioEngine::~AudioEngine () {
    context = alcGetCurrentContext();
    
    // Get device for active context
    device = alcGetContextsDevice(context);
    
    // Disable context
    alcMakeContextCurrent(NULL);
    
    // Release context(s)
    alcDestroyContext(context);
    
    // Close device
    alcCloseDevice(device);
}

void AudioEngine::playSounds (State s) {
    
}

void AudioEngine::add (AudioObject* object) { scene.push_back(object); }
