#include &lt;iostream&gt;
#include &lt;math.h&gt;
#include &lt;time.h&gt;
#include &lt;GL/glut.h&gt;
#include &lt;vector&gt;

using namespace std;

int edge;
vector&lt;int&gt; xpoint;
vector&lt;int&gt; ypoint;

int ch;

double round(double d){

return floor(d + 0.5);
}

void init(){
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,640,0,480);
glClear(GL_COLOR_BUFFER_BIT);
}

void scale(){

glColor3f(1.0,0,0);
glBegin(GL_POLYGON);
for(int i=0;i&lt;edge;i++){
glVertex2i(xpoint[i]-320,ypoint[i]-240);
}
glEnd();
glFlush();
cout&lt;&lt;&quot;\n\tIn Scaling whole screen is 1st Qudrant \n&quot;;
int sx, sy;
cout&lt;&lt;&quot;\t Enter sx, sy \n&quot;;
cin&gt;&gt; sx&gt;&gt; sy;

//scale the point
for(int i=0;i&lt;edge;i++){

xpoint[i] = (xpoint[i]-320) * sx;
ypoint[i] = (ypoint[i]-240) * sy;
}

glColor3f(0,0,1.0);
glBegin(GL_POLYGON);
for(int i=0;i&lt;edge;i++){
glVertex2i(xpoint[i],ypoint[i]);
}
glEnd();
glFlush();

}

void reflection(){
char reflection;
cout&lt;&lt;&quot;Enter Reflection Axis \n&quot;;
cin&gt;&gt; reflection;

if(reflection == &#39;x&#39; || reflection == &#39;X&#39;){

glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
for(int i=0;i&lt;edge;i++){
glVertex2i(xpoint[i], (ypoint[i] * -1)+480);
}
glEnd();
glFlush();

}
else if(reflection == &#39;y&#39; || reflection == &#39;Y&#39;){
glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
for(int i=0;i&lt;edge;i++){
glVertex2i((xpoint[i] * -1)+640,(ypoint[i]));
}
glEnd();
glFlush();
}
}

void Draw(){

if(ch==2){
glColor3f(1.0,0,0);
glBegin(GL_LINES);
glVertex2i(0,240);
glVertex2i(640,240);
glEnd();
glColor3f(1.0,0,0);
glBegin(GL_LINES);
glVertex2i(320,0);
glVertex2i(320,480);
glEnd();
glFlush();

glColor3f(1.0,0,0);
glBegin(GL_POLYGON);
for(int i=0;i&lt;edge;i++){
glVertex2i(xpoint[i],ypoint[i]);
}
glEnd();
glFlush();
}
if(ch==1){
scale();
}
else if( ch == 2){

reflection();
}

}

int main(int argc, char** argv){

cout&lt;&lt;&quot;\n \t Enter 1) Scaling &quot;;
cout&lt;&lt;&quot;\n \t Enter 2) Reflection&quot;;

cin&gt;&gt;ch;

if(ch==1 || ch==2){

cout&lt;&lt;&quot;Enter No of edges \n&quot;;
cin&gt;&gt; edge;

int xpointnew, ypointnew;
cout&lt;&lt;&quot; Enter&quot;&lt;&lt; edge &lt;&lt;&quot; point of polygon \n&quot;;
for(int i=0;i&lt;edge;i++){

cout&lt;&lt;&quot;Enter &quot;&lt;&lt; i &lt;&lt; &quot; Point &quot;;
cin&gt;&gt;xpointnew&gt;&gt;ypointnew;

xpoint.push_back(xpointnew+320);
ypoint.push_back(ypointnew+240);

}

glutInit(&amp;argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(640,480);
glutInitWindowPosition(200,200);
glutCreateWindow(&quot;2D&quot;);
init();
glutDisplayFunc(Draw);

glutMainLoop();
return 0;
}
else{
cout&lt;&lt;&quot;\n \t Check Input run again&quot;;
return 0;
}
}
