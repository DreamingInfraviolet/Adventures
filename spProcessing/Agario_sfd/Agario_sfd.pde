class Bacteria
{
  float radius;
  PVector pos = new PVector();
  boolean intersecting = false;
  
  Bacteria()
  {
    respawn();
  }
  
 void draw()
 {
   ellipse(pos.x, pos.y, radius, radius); 
 }
 
 void respawn()
 {   
   pos.x=(int)random(0, 800);
   pos.y=(int)random(0, 600);
   radius=(int)random(1,50);
 }
 
 boolean touches(Bacteria b)
 {
     float r2 = radius+b.radius;
     return r2 > pos.dist(b.pos);
 }
 
 void touch(Bacteria b)
 {
   if(touches(b))
   {
    intersecting=b.intersecting=true;
     
    if(radius>b.radius)
    {
       area(area()+b.resizeToJustTouch(this));
       if(b.radius<=0)
       b.respawn();
    }
    else
    {
       b.area(b.area()+resizeToJustTouch(b)); 
       if(radius<=0)
       respawn();
    }
   }
 }
 
 //Returns area of the amount shrunk
 float resizeToJustTouch(Bacteria b)
 {
   float area1 = area();
   radius = (int)(pos.dist(b.pos)-radius);
   
   float area2 = area();
   println(area1-area2);
   return area1-area2;
 }

 float area()
 {
     return (PI*radius*radius); 
 }
 
 void area(float a)
 {
   radius =  sqrt(a/PI);
 }
 
 void move()
 {
   pos.x+=random(-1,1);
   pos.y+=random(-1,1);
 }
}

Bacteria[] bacteria;

void setup()
{
  ellipseMode(RADIUS);
  surface.setSize(800, 600);
  bacteria = new Bacteria[100];
  for(int i = 0; i < bacteria.length; ++i)
      bacteria[i] = new Bacteria();
}

void draw()
{
  clear();
  for(Bacteria b : bacteria)
  b.intersecting=false;
  
  //Update sizes. Bigger ones eat smaller ones!
  for(int i = 0; i < bacteria.length; ++i)
  for(int j = i+1; j < bacteria.length; ++j)
     bacteria[i].touch(bacteria[j]);
     
  
  for(Bacteria b : bacteria)
  {
    if(b.intersecting)
       fill(255,0,0);
     b.draw();
     b.move();
     if(b.intersecting)
       fill(255,255,255);
  }
}