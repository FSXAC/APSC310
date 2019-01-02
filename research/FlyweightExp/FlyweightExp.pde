PImage img;
final int WIDTH = 4;
final int HEIGHT = 4;

void setup() {
    size(800, 600);
    img = loadImage("hi.png");
    noLoop();
}

void draw() {
    //background(255);
    //image(img, 0, 0);
    //drawNoFlyweight();
    drawFlyweight();
}

void drawNoFlyweight() {
    background(255);
    //textAlign(CENTER);
    int startX = 100;
    int startY = 100;
    int spaceX = 160;
    int spaceY = 120;
    for (int j = 0; j < HEIGHT; j++){
        for (int i = 0; i < WIDTH; i++) {
            int x = startX + (i * spaceX);
            int y = startY + (j * spaceY);
            image(img, x, y);
            fill(0);
            text("file: image.png (1.84KB)", x, y + 80);
            text("x: " + str(x), x, y + 95);
            text("y: " + str(y), x, y + 110);
        }
    }       
}

void drawFlyweight() {
    background(255);
    
    // draw iamge
    int imgX = width/2 - 32;
    int imgY = 30;
    image(img, imgX, imgY);
    text("file: image.png (1.84KB)", imgX + 70, imgY);
    
    // Draw data
    int startX = 100;
    int startY = 130;
    int spaceX = 160;
    int spaceY = 120;
    fill(0);
    stroke(150);
    for (int j = 0; j < HEIGHT; j++){
        for (int i = 0; i < WIDTH; i++) {
            int x = startX + (i * spaceX);
            int y = startY + (j * spaceY);
            text("file: *reference", x, y);
            text("x: " + str(x), x, y + 15);
            text("y: " + str(y), x, y + 30);
            line(x, y, imgX + 32, imgY + 32); 
        }
    }    
}