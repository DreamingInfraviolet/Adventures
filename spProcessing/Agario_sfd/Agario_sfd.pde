int screenWidth = 1300;
int screenHeight = 700;

PVector cameraPos = new PVector();

class PhysicsObject
{
  PVector pos = new PVector(); 
  PVector vel = new PVector();

  void applyVelocity(float mass)
  {
    pos=pos.add(vel.copy().div(mass));
  }

  void addVelocity(PVector v)
  {
    vel.add(v);
  }
}

class Bacteria extends PhysicsObject
{
  float radius;
  boolean intersecting = false;
  float noiseXOffset, noiseYOffset;

  Bacteria()
  {
    respawn();
  }

  void draw()
  {
    ellipse(pos.x-cameraPos.x, pos.y-cameraPos.y, radius, radius);
  }

  void respawn()
  {   
    pos.x=random(0, screenWidth);
    pos.y=random(0, screenHeight);
    radius=random(1, 2);
    noiseXOffset = random(0, 1000);
    noiseYOffset = random(0, 1000);
  }

  boolean touches(Bacteria b)
  {
    return radius+b.radius > pos.dist(b.pos);
  }

  void touch(Bacteria b)
  {
    if (touches(b))
    {
      intersecting=b.intersecting=true;

      if (radius>b.radius)
      {
        area(area()+b.resizeToJustTouch(this));
        if (b.radius<=0)
          b.respawn();
      } else
      {
        b.area(b.area()+resizeToJustTouch(b)); 
        if (radius<=0)
          respawn();
      }
    }

    applyGravity(b);
  }

  void applyGravity(Bacteria b)
  {
    float force = (0.1*area()*b.area())/(pos.dist(b.pos)*pos.dist(b.pos));
    PVector direction = b.pos.copy().sub(pos).normalize();
    addVelocity(direction.mult(force));
    b.addVelocity(direction.mult(-force));
  }

  //Returns area of the amount shrunk
  float resizeToJustTouch(Bacteria b)
  {
    //If fully inside
    if (pos.dist(b.pos) < Math.abs(radius-b.radius))
    {
      float area = area();
      radius=0;
      return area;
    }

    float area1 = area();
    radius = pos.dist(b.pos)-b.radius;
    float area2 = area();
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
    //addVelocity(new PVector(0.2, 0).mult(noise(noiseXOffset)*2-1));
    //addVelocity(new PVector(0, 0.2).mult(noise(noiseYOffset)*2-1));
    noiseXOffset+=0.04f;
    noiseYOffset+=0.04f;
    applyVelocity(area());
  }
}

Bacteria[] bacteria;

void setup()
{
  ellipseMode(RADIUS);
  surface.setSize(screenWidth, screenHeight);
  bacteria = new Bacteria[500];
  for (int i = 0; i < bacteria.length; ++i)
    bacteria[i] = new Bacteria();
  //bacteria[0].radius = 30;
  //bacteria[0].pos.set(300, 300);
}

boolean isAnyKeyPressed = false;

void keyReleased()
{
  isAnyKeyPressed=false;
}

void keyPressed()
{
  isAnyKeyPressed=true;
}

void draw()
{
  if (isAnyKeyPressed)
  {
    float cameraSpeed=4;
    if (key=='w')
      cameraPos.y-=cameraSpeed;
    if (key=='s')
      cameraPos.y+=cameraSpeed;
    if (key=='a')
      cameraPos.x-=cameraSpeed;
    if (key=='d')
      cameraPos.x+=cameraSpeed;
  }

  clear();
  for (Bacteria b : bacteria)
    b.intersecting=false;

  //Update sizes. Bigger ones eat smaller ones!
  for (int i = 0; i < bacteria.length; ++i)
  {
    for (int j = i+1; j < bacteria.length; ++j)
      bacteria[i].touch(bacteria[j]);

    if (bacteria[i].intersecting)
      fill(255, 0, 0);
    bacteria[i].draw();
    bacteria[i].move();
    if (bacteria[i].intersecting)
      fill(255, 255, 255);
  }
}