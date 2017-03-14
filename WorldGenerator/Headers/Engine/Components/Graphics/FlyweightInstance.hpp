//
//  FlyweightInstance.hpp
//  WorldGenerator
//
//  Created by Ryan Needham on 14/03/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef FlyweightInstance_hpp
#define FlyweightInstance_hpp

struct FlyweightInstance {
    public:
        FlyweightInstance (glm::vec3 p, glm::vec3 r, glm::vec4 c, glm::vec3 s):
            position   (p),
            rotation   (r),
            colour     (c),
            scale      (s) {}
    
        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec4 colour;
        glm::vec3 scale;
};

#endif /* FlyweightInstance_hpp */
