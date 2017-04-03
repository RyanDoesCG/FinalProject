float unsignedRand (float max) 
  { return (random(1) > 0.5) ? random(max) : -1 * random(max); }