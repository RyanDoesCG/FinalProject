// WINDOW
int w = 512;
int h = 512;
float image[][] = new float[w][h];

// NOISE PARAMETERS
float frequency = 0.025;
float amplitude = 128;

// FADE PARAMETERS
float fadeExp  = 2;
float fadeRate = 0.016;

// VORONOI POINTS
float voronoiExpMax = 0.04;
float voronoiExpMin = 0.02;
float voronoiExp    = (voronoiExpMin + random (voronoiExpMax - voronoiExpMin));

int nSamples = 2;//2 + floor (random (8));
PVector voronoi[] = new PVector[nSamples];
PVector nearestVoronoi (PVector from) { 
  PVector nearest = new PVector (100000, 10000);
  for (PVector v : voronoi) {
    if ((PVector.sub (v, from).mag()) < 
      (PVector.sub (nearest, from).mag()))
    nearest = v; 
  }
  return nearest;
}

float distance (float ax, float ay, float bx, float by) 
  { return PVector.dist(new PVector (ax, ay), new PVector (bx, by)); }

void setup () {
  size (512, 512);

}

float colourBass = 0;
int num = 0;

void draw () {
  background (0, 0, 0);
  
  pushMatrix ();
  
  // FIRST PASS
  frequency = 0.02;
  amplitude = 200;
  colourBass = 64;
  pass ();
  
  // SECOND PASS
  frequency = 0.025;
  amplitude = 128;
  translate (width * 0.2, height * 0.2);
  scale (0.8, 0.8);
  colourBass = 180;
  pass ();
  
  // THIRD PASS
  frequency = 0.025;
  amplitude = 128;
  translate ((width * 0.2), (width * 0.2));
  scale (0.6, 0.6);
  colourBass = 220;
  pass ();
  
  nSamples = 10;
  
  // FOURTH PASS
  frequency = 0.025;
  amplitude = 128;
  translate ((width * 0.2), (width * 0.2));
  scale (0.4, 0.4);
  colourBass = 255;
  pass ();
  
  popMatrix ();
  
  cullEdges ();
  
  // OUTPUT 
  if (num < 100) {
    save(num + ".jpg");
    num++;
  } else {
    exit();
  }
}

void cullEdges () {
  // top
  for (int x = 0; x < w; x++) {
    for (int y = 0; y < 100; y++) {
      fill(0);
      rect (x, y, 1, 1);
    }
  }
}

void pass () {
   // VORONOI
   voronoi = new PVector[nSamples];
  for (int i = 0; i < nSamples; i++) 
    voronoi[i] = new PVector(random(width - 100), random(height - 100));
  
  // MAKE IMAGE 
  for (int x = 0; x < w; x++) {
    for (int y = 0; y < h; y++) {
      
      // get some perlin
      image[x][y] = noise (x * frequency, y * frequency) * amplitude;  
     
      // fade out from voronoi
      image[x][y] *= distance (
        nearestVoronoi(new PVector(x, y)).x, 
        nearestVoronoi(new PVector(x, y)).y,
        x, y // pixel
      ) * voronoiExp;
      
      // fade out from center
      image[x][y] *= distance (
        w / 2, h / 2,  // center
        x, y           // pixel
      ) * (fadeRate * fadeExp);        // fade rate
      
    }
  }
  
  // DRAW IMAGE
  for (int x = 0; x < w; x++) {
    for (int y = 0; y < h; y++) {
        noStroke();
      
      if ((128 - ((image[x][y]) * 0.5)) > 0)
        fill ((colourBass + (128 - ((image[x][y]) * 0.5))), 100);
      else
        fill (0, 0);
        
      rect (x, y, 1, 1); //image[x][y] = noise (x, y);   
    }
  } 
}