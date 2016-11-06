/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Biome.hpp
 *  Tribes
 *
 *  Created by Ryan Needham on 03/11/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Biome_hpp
#define Biome_hpp

#include "Actor.hpp"
#include "Planet.hpp"

class Biome : public Actor {
public:
     Biome (std::vector<GLfloat>* t);
    ~Biome ();
    
    virtual void init() override;
    virtual void update(GameState state) override;
    
private:
    std::vector<GLfloat> territory;
    Planet* planet;
    
};

#endif /* Biome_hpp */
