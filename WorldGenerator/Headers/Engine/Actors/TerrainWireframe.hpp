//
//  TerrainWireframe.hpp
//  WorldGenerator
//
//  Created by user on 25/02/2017.
//  Copyright © 2017 Dissertation. All rights reserved.
//

#ifndef TerrainWireframe_hpp
#define TerrainWireframe_hpp

#include "../Utility/RegShader.hpp"
#include "../../GLEW/glew.h"

#include <OpenGL/glu.h>
#include "Actor.hpp"
#include "SceneCamera.hpp"

#define TERRAIN_WIDTH       512
#define TERRAIN_DEPTH       512
#define TERRAIN_HALF_WIDTH  TERRAIN_WIDTH  / 2
#define TERRAIN_HALF_DEPTH  TERRAIN_DEPTH / 2
#define SCALE               20
#define HALF_SCALE          SCALE / 2

#define VERT_COUNT          TERRAIN_WIDTH * TERRAIN_DEPTH
#define IND_COUNT           VERT_COUNT * 2 * 3

class TerrainWireframe : public Actor {
    public:
        TerrainWireframe ();
       ~TerrainWireframe ();

        virtual void draw   (SceneCamera* camera) override;
        virtual void update (GameState state) override;

    private:
        void makeShader ();
        void makeMesh   ();
        void makeMap    ();
  
        RegShader shader;
};

#endif /* TerrainWireframe_hpp */
