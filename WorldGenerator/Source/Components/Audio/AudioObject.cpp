//
//  AudioObject.cpp
//  WorldGenerator
//
//  Created by Ryan Needham on 17/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#include "AudioObject.hpp"

AudioObject::AudioObject (std::string name) {
    load ("Assets/music/" + name + ".wav");
}

AudioObject::~AudioObject () {
    alDeleteSources(1,&alSource);
    
        //delete our buffer
    alDeleteBuffers(1,&alSampleSet);
}

void AudioObject::play() {
    
    alSourcei(alSource,AL_LOOPING,AL_TRUE);
    
        //play
    alSourcePlay(alSource);
    
        //to stop
    alSourceStop(alSource);
}

void AudioObject::load (const std::string name) {
    // load the wave file FUNCTION CALL DEPRICATED
    // alutLoadWAVFile("my_music.wav",&alFormatBuffer, (void **) &alBuffer,(unsigned int *)&alBufferLen, &alFreqBuffer, &alLoop);
    
    
    // create a source
    alGenSources(1, &alSource);
    
    // create  buffer
    alGenBuffers(1, &alSampleSet);
    
    // put the data into our sampleset buffer
    alBufferData(alSampleSet, alFormatBuffer, alBuffer, alBufferLen, alFreqBuffer);
    
    // assign the buffer to this source
    alSourcei(alSource, AL_BUFFER, alSampleSet);
    
    // release the data FUNCTION CALL DEPRICATED
    // alutUnloadWAV(alFormatBuffer, alBuffer, alBufferLen, alFreqBuffer);
}
