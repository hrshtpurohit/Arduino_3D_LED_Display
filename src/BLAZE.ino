//initializing pins
int an[6][6] = {
  {11,12,13,14,15,16},
  {17,18,19,20,21,22},
  {23,24,25,26,27,28},
  {29,30,31,32,33,34},
  {35,36,37,38,39,40},
  {41,42,43,44,45,46}
  };
  
int cath[6] = {2,3,4,5,6,7};

//assuming pins to be like cathode from 2 to 7 and anode from 11 to 46
int c[216], a[216];


//head and tail index for snake queue position
int head, tail;

//m, n varies from 2 to 7, 11 to 46 respectively

//enqueue function for snake movement

void enq(int m, int n) 
{
  head = (head + 1)%216;
  c[head] = m;
  a[head] = n;
}


//dequeue function
void deq() 
{
  c[tail] = 0;
  a[tail] = 0;
  tail = (tail + 1)%216;
}


void printScore(int score)
{

  int k=0, pan_val;
  int pan=1;

  while(k!=3)
  {
  if(pan==1){
      pan_val = score/10;
      pan=2;
      k=0;
      for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
          digitalWrite(an[i][j], LOW);
        }
      }
  }
  else{
      pan_val = score%10;
      k=3;
  }
  switch(pan_val){
    
    case 0: 
      if(pan==1){
      break;                           //because we don't really need to display 0 at tens position;
      }
      else{
      for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
          digitalWrite(an[i][j], LOW);
        }
      }
      
      for(int j=0;j<=5;j++){
        digitalWrite(an[3][j], HIGH); 
        digitalWrite(an[5][j], HIGH);
      }
      digitalWrite(an[4][0], HIGH); 
      digitalWrite(an[4][5], HIGH); 
      
    break;
    }  
    case 1:
      
      for(int j=0;j<=5;j++){
        digitalWrite(an[3-k][j], HIGH); 
      }
      
    break;
    
    case 2:
     
      for(int j=3-k;j<=5-k;j++){
        digitalWrite(an[j][0],HIGH);
        digitalWrite(an[j][2],HIGH);
        digitalWrite(an[j][5],HIGH);
      }
      digitalWrite(an[3-k][1],HIGH);
      digitalWrite(an[5-k][3],HIGH);
      digitalWrite(an[5-k][4],HIGH);
       
    break;
    
    case 3:
      
      for(int j=3-k;j<=5-k;j++){
        digitalWrite(an[j][0],HIGH);
        digitalWrite(an[j][2],HIGH);
        digitalWrite(an[j][5],HIGH);
      }
      digitalWrite(an[3-k][1],HIGH);
      digitalWrite(an[3-k][3],HIGH);
      digitalWrite(an[3-k][4],HIGH);
       
    break;
    
    case 4:
      
      for(int j=0;j<=2;j++){
        digitalWrite(an[5-k][j],HIGH);
      }
      for(int j=0;j<=5;j++){
        digitalWrite(an[3-k][j],HIGH);
      }
      digitalWrite(an[4-k][2],HIGH);
      
    break;
    
    case 5:
      
      for(int j=3-k;j<=5-k;j++){
        digitalWrite(an[j][0],HIGH);
        digitalWrite(an[j][2],HIGH);
        digitalWrite(an[j][5],HIGH);
      }
      digitalWrite(an[5-k][1],HIGH);
      digitalWrite(an[3-k][3],HIGH);
      digitalWrite(an[3-k][4],HIGH);
       
    break;
    
   case 6:
      
      for(int j=3-k;j<=5-k;j++){
        digitalWrite(an[j][0],HIGH);
        digitalWrite(an[j][2],HIGH);
        digitalWrite(an[j][5],HIGH);
      }
      digitalWrite(an[5-k][1],HIGH);
      digitalWrite(an[5-k][3],HIGH);
      digitalWrite(an[5-k][4],HIGH);
      digitalWrite(an[3-k][3],HIGH);
      digitalWrite(an[3-k][4],HIGH);
       
    break;
    
    case 7:
         
      for(int j=3-k;j<=5-k;j++){
        digitalWrite(an[j][0],HIGH);
      }
      for(int j=0;j<=5;j++){
        digitalWrite(an[3-k][j],HIGH);
      }
      
    break;
    
    case 8:
      
      for(int j=3-k;j<=5-k;j++){
        digitalWrite(an[j][0],HIGH);
        digitalWrite(an[j][2],HIGH);
        digitalWrite(an[j][5],HIGH);
      }
      for(int j=0;j<=5;j++){
        digitalWrite(an[5-k][j],HIGH);
        digitalWrite(an[3-k][j],HIGH);
      }
      
    break;
    
    case 9:
      
      for(int j=3-k;j<=5-k;j++){
        digitalWrite(an[j][0],HIGH);
        digitalWrite(an[j][2],HIGH);
      }
      for(int j=0;j<=5;j++){
        digitalWrite(an[3-k][j],HIGH);
      }
      digitalWrite(an[5-k][1],HIGH);
      
    break;

  } 
  }
  for(int k=0; k<=5; k++){
    digitalWrite(cath[k], LOW);
    delay(200*(k+1));
    digitalWrite(cath[k], HIGH);
  }

  return;
}

void intro()
{
  
  for(int k=0;k<3;k++)
  {
    for(int i=0;i<6;i++)
    {
      digitalWrite(cath[i], LOW);
      for(int j=0;j<6;j++)
        digitalWrite(an[i][j], HIGH);
    }
    delay(500);

    for(int i=0;i<6;i++)
    {
      digitalWrite(cath[i], HIGH);
      for(int j=0;j<6;j++)
        digitalWrite(an[i][j], LOW);
    }
    delay(250);
  }
  
  for(int l=0;l<3;l++)
  {
  //H
  
  for(int i=1;i<6;i++)
  {
    for(int k=0;k<256;k++)
    {
      digitalWrite(an[0][i], HIGH);
      digitalWrite(an[0][i-1], HIGH);
      for(int j=0;j<6;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      digitalWrite(an[0][i], LOW);
      digitalWrite(an[0][i-1], LOW);



      digitalWrite(an[1][i], HIGH);
      digitalWrite(an[1][i-1], HIGH);
      for(int j=0;j<6;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      digitalWrite(an[1][i], LOW);
      digitalWrite(an[1][i-1], LOW);


      digitalWrite(an[2][i], HIGH);
      digitalWrite(an[2][i-1], HIGH);
      for(int j=2;j<4;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      digitalWrite(an[2][i], LOW);
      digitalWrite(an[2][i-1], LOW);



      digitalWrite(an[3][i], HIGH);
      digitalWrite(an[3][i-1], HIGH);
      for(int j=2;j<4;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      digitalWrite(an[3][i], LOW);
      digitalWrite(an[3][i-1], LOW);


  
      digitalWrite(an[4][i], HIGH);
      digitalWrite(an[4][i-1], HIGH);
      for(int j=0;j<6;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      digitalWrite(an[4][i], LOW);
      digitalWrite(an[4][i-1], LOW);



      digitalWrite(an[5][i], HIGH);
      digitalWrite(an[5][i-1], HIGH);
      for(int j=0;j<6;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      digitalWrite(an[5][i], LOW);
      digitalWrite(an[5][i-1], LOW);
    }
  }


  //O
  
  for(int i=1;i<6;i++)
  {
    for(int k=0;k<256;k++)
    {
      digitalWrite(an[0][i], HIGH);
      digitalWrite(an[0][i-1], HIGH);
      for(int j=0;j<6;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      digitalWrite(an[0][i], LOW);
      digitalWrite(an[0][i-1], LOW);



      digitalWrite(an[1][i], HIGH);
      digitalWrite(an[1][i-1], HIGH);
      for(int j=0;j<6;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      digitalWrite(an[1][i], LOW);
      digitalWrite(an[1][i-1], LOW);


      digitalWrite(an[2][i], HIGH);
      digitalWrite(an[2][i-1], HIGH);
      for(int j=0;j<2;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      for(int j=4;j<6;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      digitalWrite(an[2][i], LOW);
      digitalWrite(an[2][i-1], LOW);



      digitalWrite(an[3][i], HIGH);
      digitalWrite(an[3][i-1], HIGH);
      for(int j=0;j<2;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      for(int j=4;j<6;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      digitalWrite(an[3][i], LOW);
      digitalWrite(an[3][i-1], LOW);


  
      digitalWrite(an[4][i], HIGH);
      digitalWrite(an[4][i-1], HIGH);
      for(int j=0;j<6;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      digitalWrite(an[4][i], LOW);
      digitalWrite(an[4][i-1], LOW);



      digitalWrite(an[5][i], HIGH);
      digitalWrite(an[5][i-1], HIGH);
      for(int j=0;j<6;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      digitalWrite(an[5][i], LOW);
      digitalWrite(an[5][i-1], LOW);
    }
  }


  //L
  
  for(int i=1;i<6;i++)
  {
    for(int k=0;k<256;k++)
    {
      digitalWrite(an[0][i], HIGH);
      digitalWrite(an[0][i-1], HIGH);
      for(int j=0;j<2;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      digitalWrite(an[0][i], LOW);
      digitalWrite(an[0][i-1], LOW);



      digitalWrite(an[1][i], HIGH);
      digitalWrite(an[1][i-1], HIGH);
      for(int j=0;j<2;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      digitalWrite(an[1][i], LOW);
      digitalWrite(an[1][i-1], LOW);


      digitalWrite(an[2][i], HIGH);
      digitalWrite(an[2][i-1], HIGH);
      for(int j=0;j<2;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      digitalWrite(an[2][i], LOW);
      digitalWrite(an[2][i-1], LOW);



      digitalWrite(an[3][i], HIGH);
      digitalWrite(an[3][i-1], HIGH);
      for(int j=0;j<2;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      digitalWrite(an[3][i], LOW);
      digitalWrite(an[3][i-1], LOW);


  
      digitalWrite(an[4][i], HIGH);
      digitalWrite(an[4][i-1], HIGH);
      for(int j=0;j<6;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      digitalWrite(an[4][i], LOW);
      digitalWrite(an[4][i-1], LOW);



      digitalWrite(an[5][i], HIGH);
      digitalWrite(an[5][i-1], HIGH);
      for(int j=0;j<6;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      digitalWrite(an[5][i], LOW);
      digitalWrite(an[5][i-1], LOW);
    }
  }


  //A
  
  for(int i=1;i<6;i++)
  {
    for(int k=0;k<256;k++)
    {
      digitalWrite(an[0][i], HIGH);
      digitalWrite(an[0][i-1], HIGH);
      for(int j=0;j<5;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      digitalWrite(an[0][i], LOW);
      digitalWrite(an[0][i-1], LOW);



      digitalWrite(an[1][i], HIGH);
      digitalWrite(an[1][i-1], HIGH);
      for(int j=0;j<6;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      digitalWrite(an[1][i], LOW);
      digitalWrite(an[1][i-1], LOW);


      digitalWrite(an[2][i], HIGH);
      digitalWrite(an[2][i-1], HIGH);
      for(int j=2;j<3;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      for(int j=4;j<6;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      digitalWrite(an[2][i], LOW);
      digitalWrite(an[2][i-1], LOW);



      digitalWrite(an[3][i], HIGH);
      digitalWrite(an[3][i-1], HIGH);
      for(int j=2;j<3;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      for(int j=4;j<6;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      digitalWrite(an[3][i], LOW);
      digitalWrite(an[3][i-1], LOW);


  
      digitalWrite(an[4][i], HIGH);
      digitalWrite(an[4][i-1], HIGH);
      for(int j=0;j<6;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      digitalWrite(an[4][i], LOW);
      digitalWrite(an[4][i-1], LOW);



      digitalWrite(an[5][i], HIGH);
      digitalWrite(an[5][i-1], HIGH);
      for(int j=0;j<5;j++)
      {
        digitalWrite(cath[j], LOW);
        digitalWrite(cath[j], HIGH);
      }
      digitalWrite(an[5][i], LOW);
      digitalWrite(an[5][i-1], LOW);
    }
  }

  delay(500);
  }
  return;
}

void runSnake()
{

  char charrec;
  
  //snake mouth position
  int x, y, z;

  //direction can be +1 for +x, -1 for -x, +2 for +y, -2 for -y, +3 for +z, -3 for -z
  int dir;


  //for score purpose
  int score;
  
  start:
  
  //initializing snake to be dead
  for(int i=0;i<216;i++) 
  {
    c[i]=0;
    a[i]=0; 
  }
  
  //setting up initial snake
  head = 2;
  tail = 0;
  
  //putting snake in queue
  a[0] = an[2][1];
  c[0] = cath[2];
  a[1] = an[2][2];
  c[1] = cath[2];
  a[2] = an[2][3];
  c[2] = cath[2];

  //setting up initial direction 
  dir = 2;
  
  //initializing index for mouth of snake   x - cath[i]    y - an[i][]    z - an[][i]
  x = 2;
  y = 2;
  z = 3;

  //initializing score
  score = 0;
  
  //initializing the board to be not display
  for(int i=0;i<6;i++)
  {
    digitalWrite(cath[i], HIGH);
  }
  
  for(int i=0;i<6;i++)
  {
    for(int j=0;j<6;j++)
    {
      digitalWrite(an[i][j], LOW);  
    }
  }
  
  // generating random food

  for(int l=0;l<2;l++)
  {
    for(int i=0;i<(4096/(score+1));i++)
    {
      for(int j=tail;j!=(head+1)%216;j=(j+1)%216)
      {
        digitalWrite(a[j], HIGH);
        digitalWrite(c[j], LOW);
        digitalWrite(a[j], LOW);
        digitalWrite(c[j], HIGH);

      }
    }
    delay(50);
  }

  
  
   
  food:
  int p = random(cath[0],cath[5]+1);
  int q = random(an[0][0],an[5][5]+1);

  for(int i=tail;i!=(head+1)%216;i=(i+1)%216)
  {
    if(c[i]==p && a[i]==q)
    {
      goto food;
    }
  }

  //movement of snake

  
  moveon: 
  
  for(int i=0;i<(4096/(score+1));i++)
  {
    for(int j=tail;j!=head%216;j=(j+1)%216)
    {
      digitalWrite(a[j], HIGH);
      digitalWrite(c[j], LOW);
      digitalWrite(a[j], LOW);
      digitalWrite(c[j], HIGH);
      
      if(i < (3144/(score+1)))
      {
        digitalWrite(a[head], HIGH);
        digitalWrite(c[head], LOW);
        digitalWrite(a[head], LOW);
        digitalWrite(c[head], HIGH);
      }

      if(i < (2048/(score+1)))
      {
        digitalWrite(q, HIGH);
        digitalWrite(p, LOW);
        digitalWrite(q, LOW);
        digitalWrite(p, HIGH);
      }
    }
    
    //input
    
    if (Serial.available()>0)
      {
      charrec = ((byte) Serial.read());
    } 
  }


  int turn=dir;
  if(charrec == 'd')
  {
    turn = 1;
  }
  if(charrec == 'w')
  {
    turn = 2;
  }
  if(charrec == 'a')
  {
    turn = -1;
  }
  if(charrec == 's')
  {
    turn = -2;
  }
  if(charrec == 'q')
  {
    turn = 3;
  }
  if(charrec == 'e')
  {
    turn = -3;
  }
  if(charrec == 'x')
  {
    return;
  }
  
  //changing direction according to input (if input is made)
  if(abs(turn)!=abs(dir))
  {
    dir = turn;
  }

  //incrementing snake
  switch(dir)
  {
    case 1:
      y = (y+1)%6;
      break;
    case -1:
      y = 5-(6-y)%6;
      break;
    case 2:
      z = (z+1)%6;      
      break;
    case -2:
      z = 5-(6-z)%6;
      break;
    case +3:
      x = (x+1)%6;
      break;
    case -3:
      x = 5-(6-x)%6;
      break;
  }

  enq(cath[x], an[y][z]);

  //if snake eats then incrementing length
  
  if(a[head] == q && c[head] == p)
  {
      score = score+1;
      goto food;
  }
  else
  {
    deq();
  }
  
  //if snake dies
  
  for(int i=tail;i<head%216;i=(i+1)%216)
  {
    if(cath[x] == c[i] && an[y][z] == a[i])
    {


      for(int l=0;l<2;l++)
      {
        for(int k=0;k<(4096/(score+1));k++)
        {
          for(int j=tail;j!=(head+1)%216;j=(j+1)%216)
          {
            digitalWrite(a[j], HIGH);
            digitalWrite(c[j], LOW);
            digitalWrite(a[j], LOW);
            digitalWrite(c[j], HIGH);
          }
        }
        delay(500);
      }
      
      Serial.print(score);
      printScore(score);
      return;
    }
  }
  
  goto moveon;
}




void runShoot()
{

  char charrec;
  //for score purpose
  int score = 0;
  int sf=2000;

  start:
  
  //initializing the board to be not display

  for(int i=0;i<6;i++)
  {
    for(int j=0;j<6;j++)
      digitalWrite(an[i][j], LOW);
  }
  for(int i=0;i<6;i++)
  {
    digitalWrite(cath[i], HIGH);
  }
  
  
  int dir = random(-3, 4);
  
  if(dir == 0)
    goto start;


  if(dir == 1)
  {
    for(int i=0;i<6;i++)
    {
      digitalWrite(cath[i], LOW);
    }
    
    int i;
    for(i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
          digitalWrite(an[i][j], HIGH);
        }
      delay(sf/1.1);
      sf=sf/1.1;  
      if (Serial.available()>0)
      {
        charrec = Serial.read();
      }
      if(charrec == 'x')
      {
        return;
      }
      if(charrec == 'a')
      {
        
        //draw gate open

        for(int j=0;j<3;j++)
        {
          digitalWrite(an[i][2-j], LOW);
          digitalWrite(an[i][3+j], LOW);
          delay(100);
        }
        
        score++;

        
        
        break;
      }

      for(int j=0;j<6;j++)
      {
        digitalWrite(an[i][j], LOW);
      }
    }
    if(i==6)
    { 
      
      //game over display score

      for(int j=0;j<6;j++)
      {
      digitalWrite(cath[j], HIGH);
      }

      Serial.write(score);
      printScore(score);
      return;
    }
    
    //undisplay
    for(int i=0;i<6;i++)
    {
      digitalWrite(cath[i], HIGH);
    }     
  }



  if(dir == -1)
  {
    for(int i=0;i<6;i++)
    {
      digitalWrite(cath[i], LOW);
    }
    int i;
    for(i=5;i>=0;i--)
    {

        for(int j=0;j<6;j++)
        {
          digitalWrite(an[i][j], HIGH);
        }
      delay(sf/1.1);
      sf=sf/1.1;
      if (Serial.available()>0)
      {
        charrec = Serial.read();
      }
      if(charrec == 'x')
      {
        return;
      }
      if(charrec == 'd')
      {
        //draw gate open

        
        for(int j=0;j<3;j++)
        {
          digitalWrite(an[i][2-j], LOW);
          digitalWrite(an[i][3+j], LOW);
          delay(100);
        }
        
        score++;


        break;
      }
      for(int j=0;j<6;j++)
      {
        digitalWrite(an[i][j], LOW);
      }      
    }
    if(i==-1)
    {
      //game over display score

      for(int j=0;j<6;j++)
      {
        digitalWrite(cath[j], HIGH);
      } 
      Serial.print(score);
      printScore(score);
      return;
    }
     
    //undisplay
    for(int i=0;i<6;i++)
    {
      digitalWrite(cath[i], HIGH);
    }  
  }



  if(dir == 2)
  {
    for(int i=0;i<6;i++)
    {
      digitalWrite(cath[i], LOW);
    }
    int i;
    for(i=0;i<6;i++)
    {

        for(int j=0;j<6;j++)
        {
          digitalWrite(an[j][i], HIGH);
        }
      delay(sf/1.1);
      sf=sf/1.1;
      if (Serial.available()>0)
      {
        charrec = Serial.read();
      }
      if(charrec == 'x')
      {
        return;
      }
      if(charrec == 's')
      {
        //draw gate open

        for(int j=0;j<3;j++)
        {
          digitalWrite(an[2-j][i], LOW);
          digitalWrite(an[3+j][i], LOW);
          delay(100);
        }
        
        score++;

          
        break;
      }
      for(int j=0;j<6;j++)
      {
        digitalWrite(an[j][i], LOW);
      }
    }
    if(i==6)
    {
      //game over display score

      for(int j=0;j<6;j++)
      {
        digitalWrite(cath[j], HIGH);
      }
    
      Serial.print(score);
      printScore(score);
      return;
    }
    
    //undisplay
    for(int i=0;i<6;i++)
    {
      digitalWrite(cath[i], HIGH);
    }
  }

  if(dir == -2)
  {
    for(int i=0;i<6;i++)
    {
      digitalWrite(cath[i], LOW);
    }
    int i;
    for(i=5;i>=0;i--)
    {

        for(int j=0;j<6;j++)
        {
          digitalWrite(an[j][i], HIGH);
        }
      delay(sf/1.1);
      sf=sf/1.1;
      if (Serial.available()>0)
      {
        charrec = Serial.read();
      }
      if(charrec == 'x')
      {
        return;
      }
      if(charrec == 'w')
      {
        //draw gate open

        for(int j=0;j<3;j++)
        {
          digitalWrite(an[2-j][i], LOW);
          digitalWrite(an[3+j][i], LOW);
          delay(100);
        }
        
        score++;


        break;
      }
      for(int j=0;j<6;j++)
      {
        digitalWrite(an[j][i], LOW);
      }
    }
    if(i==-1)
    {
      //game over display score

      for(int j=0;j<6;j++)
      {
        digitalWrite(cath[j], HIGH);
      }
      Serial.print(score);
      printScore(score);
      return;
    }
    
    for(int i=0;i<6;i++)
    {
      digitalWrite(cath[i], HIGH);
    }
  }



  if(dir == 3)
  {
    for(int i=0;i<6;i++)
    {
      for(int j=0;j<6;j++)
      {
        digitalWrite(an[i][j], HIGH);
    
      }
    }
    int i;
    for(i=0;i<6;i++)
    {

        digitalWrite(cath[i], LOW);
        delay(sf/1.1);
        sf=sf/1.1;
      if (Serial.available()>0)
      {
        charrec = Serial.read();
      }
      if(charrec == 'x')
      {
        return;
      }
      if(charrec == 'e')
      {
        //draw gate open
         for(int j=0;j<3;j++)
          {
            for(int l=0;l<6;l++)
            {
              digitalWrite(an[2-j][l], LOW);
              digitalWrite(an[3+j][l], LOW);
            }
            delay(100);
          }
        
        score++;

        
        break;
      }

      digitalWrite(cath[i], HIGH);
    }
    if(i==6)
    {
      //game over display score

      for(int k=0;k<6;k++)
      {
        for(int j=0;j<6;j++)
        {
          digitalWrite(an[k][j], LOW);
        }
      }
      Serial.print(score);
      printScore(score);
      return;
    }
    
    //undisplay
    for(int i=0;i<6;i++)
    {
      for(int j=0;j<6;j++)
      {
        digitalWrite(an[i][j], LOW);
      }
    }
  }


  if(dir == -3)
  {
    for(int i=0;i<6;i++)
    {
      for(int j=0;j<6;j++)
      {
        digitalWrite(an[i][j], HIGH);
      }
    }
    int i;
    for(i=5;i>=0;i--)
    {

        digitalWrite(cath[i], LOW);

      delay(sf/1.1);
      sf=sf/1.1;
      if (Serial.available()>0)
      {
        charrec = Serial.read();
      }
      if(charrec == 'x')
      {
        return;
      }
      if(charrec == 'q')
      {
        //draw gate open

          for(int j=0;j<3;j++)
          {
            for(int l=0;l<6;l++)
            {
              digitalWrite(an[2-j][l], LOW);
              digitalWrite(an[3+j][l], LOW);
            }
            delay(100);
          }
        score++;
        
        break;
      }

      digitalWrite(cath[i], HIGH);
    }
    if(i==-1)
    {
      //game over display score

      

      for(int k=0;k<6;k++)
      {
        for(int j=0;j<6;j++)
        {
          digitalWrite(an[k][j], LOW);
        }
      }
      Serial.print(score);
      printScore(score);
      return;
    }
    
    //undisplay
    for(int i=0;i<6;i++)
    {
      for(int j=0;j<6;j++)
      {
        digitalWrite(an[i][j], LOW);
      }
    }
  }
  
  goto start;

  
}







void runGraph() 
{
  int values[6][6],val[6][6];

  float mini;
  float maxi; 
  float a,d;

  String inString = ""; 
  
  //zeroing all values
  for(int i=0;i<6;i++)
  {
    for(int j=0;j<6;j++)
    {
        values[i][j] = 0;
    }
  }


  //filling in values
  for(int i=0;i<6;i++)
  {
    for(int j=0;j<6;j++)
    {
      while(Serial.available()==0);
      if (Serial.available()>0)
      {
        int x= Serial.parseInt();
        values[i][j] = x;
        Serial.println(x);
      }
    }
  }

 
  
  mini=10000; 
  for(int i=0;i<6;i++)
  {
    for(int j=0;j<6;j++)
    {
      if(values[i][j]<mini){
        mini=values[i][j];
      }
    }
  }

  
  maxi=0; 
  for(int i=0;i<6;i++)
  {
    for(int j=0;j<6;j++)
    {
      if(values[i][j]>maxi){
        maxi=values[i][j];
      }
    }
  }

 
  
  d=(maxi-mini)/5;
  a=mini;
  
  for(int k=5; k>=0; k--)
  {
    for(int i=0;i<6;i++)
    {
      for(int j=0;j<6;j++)
      { 
        if(values[i][j]<=(a+(k*d)) && values[i][j]>(a+((k-1)*d))) 
          val[i][j]=k;
      }
    }
  }

  carryon:
  //all anodes high

  for(int i=0;i<6;i++)
      {
        for(int j=0;j<6;j++){
           digitalWrite(an[i][j], HIGH);
          }
      }
  
  
  for(int k=0; k<6; k++)
  {
     //cathode k low
     
     
     
     for(int i=0;i<6;i++)
      {
        for(int j=0;j<6;j++)
          {
             if(val[i][j]<k){
                //lower this anode
                digitalWrite(an[i][j], LOW);
                }
          }
      }
     digitalWrite(cath[k], LOW);
     //int a=0;
     //for(int i=0; i<=100; i++){
     //a++;
      Serial.println(k);
     // }
     digitalWrite(cath[k], HIGH); 
     
  }
  
  goto carryon;
}






void runBeat()
{
  int spd = 1;
  
  again:



////////////////////////////////////////////pattern 1

  
  for(int t=0;t<50;t++){
    for(int i=0;i<6;i++) {
    for(int l=0;l<200/(spd+1);l++)
    {
    //-3
    for(int m=0;m<6;m++);
      digitalWrite(cath[i], LOW);

    for(int j=0;j<6;j++)
    {
      for(int k=0;k<6;k++)
        digitalWrite(an[j][k], HIGH);  
    }  
      
    for(int m=0;m<6;m++);
    digitalWrite(cath[i], HIGH);

    for(int j=0;j<6;j++)
    {
      for(int k=0;k<6;k++)
        digitalWrite(an[j][k], LOW);  
    }


    //3
    for(int m=0;m<6;m++);
      digitalWrite(cath[5-i], LOW);

    for(int j=0;j<6;j++)
    {
      for(int k=0;k<6;k++)
        digitalWrite(an[j][k], HIGH);  
    }  
      
    for(int m=0;m<6;m++);
      digitalWrite(cath[5-i], HIGH);

    for(int j=0;j<6;j++)
    {
      for(int k=0;k<6;k++)
        digitalWrite(an[j][k], LOW);  
    }


  
    for(int j=0;j<6;j++)
      digitalWrite(cath[j], LOW);
    
   for(int m=0;m<3;m++)
   {
    for(int j=0;j<6;j++)
    {
        digitalWrite(an[i][j], HIGH);  
    }  
   }

      
    for(int j=0;j<6;j++)
      digitalWrite(cath[j], HIGH);

  for(int m=0;m<3;m++)
   {
    for(int j=0;j<6;j++)
    {
        digitalWrite(an[i][j], LOW);  
    }
   }


    for(int j=0;j<6;j++)
      digitalWrite(cath[j], LOW);
  
  for(int m=0;m<3;m++)
  {
    for(int j=0;j<6;j++)
    {
        digitalWrite(an[5-i][j], HIGH);  
    }  
  }

      
    for(int j=0;j<6;j++)
      digitalWrite(cath[j], HIGH);
  
  for(int m=0;m<3;m++)
  {
    for(int j=0;j<6;j++)
    {
        digitalWrite(an[5-i][j], LOW);  
    }    
  }


    for(int j=0;j<6;j++)
      digitalWrite(cath[j], LOW);


  for(int m=0;m<3;m++)
  {
    for(int j=0;j<6;j++)
    {
        digitalWrite(an[j][i], HIGH);  
    }  
  }      
    for(int j=0;j<6;j++)
      digitalWrite(cath[j], HIGH);

  for(int m=0;m<3;m++)
  {
    for(int j=0;j<6;j++)
    {
        digitalWrite(an[j][i], LOW);  
    }
  }
  


    for(int j=0;j<6;j++)
      digitalWrite(cath[j], LOW);


  for(int m=0;m<3;m++)
  {
    for(int j=0;j<6;j++)
    {
        digitalWrite(an[j][5-i], HIGH);  
    }  
  }   
    for(int j=0;j<6;j++)
      digitalWrite(cath[j], HIGH);

  for(int m=0;m<3;m++)
  {
    for(int j=0;j<6;j++)
    {
        digitalWrite(an[j][5-i], LOW);  
    }
  }
    
    if(Serial.available()>0)
    spd = Serial.read() - '0';
  }

  }
  }


//////////////////////////////////////////////


//////////////////////////////////////pattern 2


  for(int t=0;t<30;t++)
  {

  for(int i=0;i<3;i++)
  {
    for(int m=0;m<6;m++);
      digitalWrite(cath[i], LOW);

    for(int j=i;j<6-i;j++)
    {
      for(int k=i;k<6-i;k++)
        digitalWrite(an[j][k], HIGH);  
    }



    for(int m=0;m<6;m++);
      digitalWrite(cath[5-i], LOW);

    for(int j=i;j<6-i;j++)
    {
      for(int k=i;k<6-i;k++)
        digitalWrite(an[j][k], HIGH);  
    }  

      

  
    for(int j=i;j<-i;j++)
      digitalWrite(cath[j], LOW);
    
   for(int m=0;m<3;m++)
   {
    for(int j=i;j<6-i;j++)
    {
        digitalWrite(an[i][j], HIGH);  
    }  
   }



    for(int j=i;j<6-i;j++)
      digitalWrite(cath[j], LOW);
  
  for(int m=0;m<3;m++)
  {
    for(int j=i;j<6-i;j++)
    {
        digitalWrite(an[5-i][j], HIGH);  
    }  
  }

      

    for(int j=i;j<6-i;j++)
      digitalWrite(cath[j], LOW);


  for(int m=0;m<3;m++)
  {
    for(int j=i;j<6-i;j++)
    {
        digitalWrite(an[j][i], HIGH);  
    }  
  }      
  


    for(int j=i;j<6-i;j++)
      digitalWrite(cath[j], LOW);


  for(int m=0;m<3;m++)
  {
    for(int j=i;j<6-i;j++)
    {
        digitalWrite(an[j][5-i], HIGH);  
    }  
  }   

  if(Serial.available()>0)
    spd = Serial.read() - '0';

  delay(600/(spd+1));

  
  
  for(int i=0;i<6;i++)
  {
    for(int j=0;j<6;j++)
    {
      digitalWrite(an[i][j], LOW);
    }
  }

  for(int i=0;i<6;i++)
  {
    digitalWrite(cath[i], HIGH);
  }

  }


    for(int m=0;m<6;m++);
      digitalWrite(cath[1], LOW);

    for(int j=1;j<5;j++)
    {
      for(int k=1;k<5;k++)
        digitalWrite(an[j][k], HIGH);  
    }



    for(int m=0;m<6;m++);
      digitalWrite(cath[4], LOW);

    for(int j=1;j<5;j++)
    {
      for(int k=1;k<5;k++)
        digitalWrite(an[j][k], HIGH);  
    }  

      

  
    for(int j=1;j<-1;j++)
      digitalWrite(cath[j], LOW);
    
   for(int m=0;m<3;m++)
   {
    for(int j=1;j<5;j++)
    {
        digitalWrite(an[1][j], HIGH);  
    }  
   }



    for(int j=1;j<5;j++)
      digitalWrite(cath[j], LOW);
  
  for(int m=0;m<3;m++)
  {
    for(int j=1;j<5;j++)
    {
        digitalWrite(an[4][j], HIGH);  
    }  
  }

      

    for(int j=1;j<5;j++)
      digitalWrite(cath[j], LOW);


  for(int m=0;m<3;m++)
  {
    for(int j=1;j<5;j++)
    {
        digitalWrite(an[j][1], HIGH);  
    }  
  }      
  


    for(int j=1;j<5;j++)
      digitalWrite(cath[j], LOW);


  for(int m=0;m<3;m++)
  {
    for(int j=1;j<5;j++)
    {
        digitalWrite(an[j][4], HIGH);  
    }  
  }   

  if(Serial.available()>0)
    spd = Serial.read() - '0';

  delay(600/(spd+1));

  
  

  for(int i=0;i<6;i++)
  {
    for(int j=0;j<6;j++)
    {
      digitalWrite(an[i][j], LOW);
    }
  }

  for(int i=0;i<6;i++)
  {
    digitalWrite(cath[i], HIGH);
  }
  }



////////////////////////////////////////////////////////////




////////////////////////////////////////////////////pattern 3


  int flag[3] = {0,0,0};
  int x = 2;
  int y = 1;
  int z = 0;

  for(int t=0;t<400;t++)
  {
  for(int k=0;k<512/(spd+1);k++)
  {
      digitalWrite(cath[x], LOW);
      for(int i=0;i<5;i++)
      {
        digitalWrite(an[0][i], HIGH);
        digitalWrite(an[0][i], LOW);
      }
      for(int i=0;i<5;i++)
      {
        digitalWrite(an[i][5], HIGH);
        digitalWrite(an[i][5], LOW);
      }
      for(int i=1;i<6;i++)
      {
        digitalWrite(an[5][i], HIGH);
        digitalWrite(an[5][i], LOW);
      }
      for(int i=1;i<6;i++)
      {
        digitalWrite(an[i][0], HIGH);
        digitalWrite(an[i][0], LOW);
      }
      digitalWrite(cath[x], HIGH);
      


      digitalWrite(cath[y], LOW);
      for(int i=1;i<4;i++)
      {
        digitalWrite(an[1][i], HIGH);
        digitalWrite(an[1][i], LOW);
      }
      for(int i=1;i<4;i++)
      {
        digitalWrite(an[i][4], HIGH);
        digitalWrite(an[i][4], LOW);
      }
      for(int i=2;i<5;i++)
      {
        digitalWrite(an[4][i], HIGH);
        digitalWrite(an[4][i], LOW);
      }
      for(int i=2;i<5;i++)
      {
        digitalWrite(an[i][1], HIGH);
        digitalWrite(an[i][1], LOW);
      }
      digitalWrite(cath[y], HIGH);
      



      digitalWrite(cath[z], LOW);
      for(int i=2;i<3;i++)
      {
        digitalWrite(an[2][i], HIGH);
        digitalWrite(an[2][i], LOW);
      }
      for(int i=2;i<3;i++)
      {
        digitalWrite(an[i][3], HIGH);
        digitalWrite(an[i][3], LOW);
      }
      for(int i=3;i<4;i++)
      {
        digitalWrite(an[3][i], HIGH);
        digitalWrite(an[3][i], LOW);
      }
      for(int i=3;i<4;i++)
      {
        digitalWrite(an[i][2], HIGH);
        digitalWrite(an[i][2], LOW);
      }
      digitalWrite(cath[z], HIGH);


      
      if(Serial.available()>0)
      spd = Serial.read() - '0';

   }

    if(x==0)
      flag[0]=0;
    else if(x==5)
      flag[0]=1;
      
    if(flag[0]==0)
      x++;
    else
      x--;

    if(y==0)
      flag[1]=0;
    else if(y==5)
      flag[1]=1;
      
    if(flag[1]==0)
      y++;
    else
      y--;

      
    if(z==0)
      flag[2]=0;
    else if(z==5)
      flag[2]=1;
      
    if(flag[2]==0)
      z++;
    else
      z--;

  }


/////////////////////////////////////////////////////////////////

  
////////////////////////////////////////////////////////////pattern 4

  for(int t=0;t<150;t++)
  {
  start:
  int dir = random(-3, 4);
  
  if(dir == 0)
    goto start;


  if(dir == 1)
  {
    int x = random(0,6);
    int y = random(0,6);

    digitalWrite(cath[x], LOW);
    for(int i=0;i<6;i++)
    {
        digitalWrite(an[y][i], HIGH);
        if(Serial.available()>0)
          spd = Serial.read() - '0';

        delay(100/(spd+1));
        
        digitalWrite(an[y][i], LOW);
    }  
    digitalWrite(cath[x], HIGH);  
  }



  if(dir == -1)
  {
    int x = random(0,6);
    int y = random(0,6);

    digitalWrite(cath[x], LOW);
    for(int i=5;i>=0;i--)
    {
        digitalWrite(an[y][i], HIGH);
        if(Serial.available()>0)
          spd = Serial.read() - '0';

        delay(100/(spd+1));
        
        digitalWrite(an[y][i], LOW);
    }   
    digitalWrite(cath[x], HIGH);
  }



  if(dir == 2)
  {
    int x = random(0,6);
    int y = random(0,6);

    digitalWrite(cath[x], LOW);
    for(int i=0;i<6;i++)
    {
        digitalWrite(an[i][y], HIGH);
        if(Serial.available()>0)
          spd = Serial.read() - '0';

        delay(100/(spd+1));
        
        digitalWrite(an[i][y], LOW);
    } 
    digitalWrite(cath[x], HIGH); 
  }

  if(dir == -2)
  {
    int x = random(0,6);
    int y = random(0,6);

    digitalWrite(cath[x], LOW);
    for(int i=5;i>=0;i--)
    {
        digitalWrite(an[i][y], HIGH);
        if(Serial.available()>0)
          spd = Serial.read() - '0';

        delay(100/(spd+1));
        
        digitalWrite(an[i][y], LOW);
    }   
    digitalWrite(cath[x], HIGH);
  }



  if(dir == 3)
  {
    int x = random(0,6);
    int y = random(0,6);

    digitalWrite(an[x][y], HIGH);
    for(int i=0;i<6;i++)
    {
        digitalWrite(cath[i], LOW);
        if(Serial.available()>0)
          spd = Serial.read() - '0';

        delay(100/(spd+1));
        
        digitalWrite(cath[i], HIGH);
    }   
    digitalWrite(an[x][y], LOW);
  }


  if(dir == -3)
  {
    int x = random(0,6);
    int y = random(0,6);

    digitalWrite(an[x][y], HIGH);
    for(int i=5;i>=0;i--)
    {
        digitalWrite(cath[i], LOW);
        if(Serial.available()>0)
          spd = Serial.read() - '0';

        delay(100/(spd+1));
        
        
        digitalWrite(cath[i], HIGH);
    }
    digitalWrite(an[x][y], LOW);
  }
  }


/////////////////////////////////////////////////////////
  


/////////////////////////////////////////////////pattern 5

  for(int t=0;t<50;t++)
  {
  int x = random(0,6);
  int y = random(0,6);
  
  
  for(int i=4;i>=0;i--)
  {
    for(int k=0;k<200/(spd+1);k++)
    {
    digitalWrite(cath[5], LOW);
    for(int j=0;j<6;j++)
    {
      for(int l=0;l<6;l++)
      {
        if(j!=x || l!=y)
          digitalWrite(an[j][l], HIGH);
      }
    }

    for(int j=0;j<6;j++)
    {
      for(int l=0;l<6;l++)
        digitalWrite(an[j][l], LOW);
    }
    digitalWrite(cath[5], HIGH);


    
    digitalWrite(cath[i], LOW);
    digitalWrite(an[x][y], HIGH);
    digitalWrite(an[x][y], LOW);
    digitalWrite(cath[i], HIGH);

    
    if(Serial.available()>0)
      spd = Serial.read() - '0';
    
    }
  }

  for(int i=1;i<6;i++)
  {
    for(int k=0;k<200/(spd+1);k++)
    {
    digitalWrite(cath[5], LOW);
    for(int j=0;j<6;j++)
    {
      for(int l=0;l<6;l++)
      {
        if(j!=x || l!=y)
          digitalWrite(an[j][l], HIGH);
      }
    }

    for(int j=0;j<6;j++)
    {
      for(int l=0;l<6;l++)
        digitalWrite(an[j][l], LOW);
    }
    digitalWrite(cath[5], HIGH);


    
    digitalWrite(cath[i], LOW);
    digitalWrite(an[x][y], HIGH);
    digitalWrite(an[x][y], LOW);
    digitalWrite(cath[i], HIGH);

    
    if(Serial.available()>0)
      spd = Serial.read() - '0';
    
    }
  }
  }

/////////////////////////////////////////////////////////////////////////////
  





/////////////////////////////////////////////////////////////////pattern 6


for(int t=0;t<2;t++)
{
for(int k=0;k<=2;k++){
  for(int n=1;n<=2;n++){
  digitalWrite(cath[5-k], LOW);
  
  for(int i=0+k;i<=5-k;i++){
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[i][j], HIGH); 
      }

      
      if(Serial.available()>0)
        spd = Serial.read() - '0';

        delay(150/(spd+1));
      

      
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[i][j], LOW); 
      }
  }

  digitalWrite(cath[5-k], HIGH);
  
  for(int i=5-k;i>=0+k;i--){
      digitalWrite(cath[i], LOW);
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[i][j], HIGH); 
      } 

      
      if(Serial.available()>0)
        spd = Serial.read() - '0';

        delay(150/(spd+1));
      

      
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[i][j], LOW); 
      }
      digitalWrite(cath[i], HIGH);
  }

  digitalWrite(cath[0+k], LOW);

  for(int i=0;i<=5;i++){
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[i][j], HIGH); 
      }

      
      if(Serial.available()>0)
        spd = Serial.read() - '0';

        delay(150/(spd+1));
      

      
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[i][j], LOW); 
      }
  }

  digitalWrite(cath[0+k], HIGH);

  for(int i=5-k;i>=0+k;i--){
      digitalWrite(cath[5-i], LOW);
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[i][j], HIGH); 
      } 

      
      if(Serial.available()>0)
        spd = Serial.read() - '0';

        delay(150/(spd+1));
      

      
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[i][j], LOW); 
      }
      digitalWrite(cath[5-i], HIGH);
  }
}
}




for(int k=2;k>=0;k--){
  for(int n=1;n<=2;n++){
  digitalWrite(cath[5-k], LOW);
  
  for(int i=0+k;i<=5-k;i++){
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[j][i], HIGH); 
      }
      

      if(Serial.available()>0)
        spd = Serial.read() - '0';

        delay(150/(spd+1));
      
      

      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[j][i], LOW); 
      }
  }

  digitalWrite(cath[5-k], HIGH);
  
  for(int i=5-k;i>=0+k;i--){
      digitalWrite(cath[i], LOW);
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[j][i], HIGH); 
      } 

      
      if(Serial.available()>0)
        spd = Serial.read() - '0';

        delay(150/(spd+1));
      

      
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[j][i], LOW); 
      }
      digitalWrite(cath[i], HIGH);
  }

  digitalWrite(cath[0+k], LOW);

  for(int i=0;i<=5;i++){
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[j][i], HIGH); 
      }

      
      if(Serial.available()>0)
        spd = Serial.read() - '0';

        delay(150/(spd+1));
      

      
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[j][i], LOW); 
      }
  }

  digitalWrite(cath[0+k], HIGH);

  for(int i=5-k;i>=0+k;i--){
      digitalWrite(cath[5-i], LOW);
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[j][i], HIGH); 
      } 

      
      if(Serial.available()>0)
        spd = Serial.read() - '0';

        delay(150/(spd+1));
      

      
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[j][i], LOW); 
      }
      digitalWrite(cath[5-i], HIGH);
  }
}
}


for(int k=0;k<=2;k++){
  for(int n=1;n<=2;n++){
  digitalWrite(cath[5-k], LOW);
  
  for(int i=0+k;i<=5-k;i++){
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[j][i], HIGH); 
      }

      
      if(Serial.available()>0)
        spd = Serial.read() - '0';

        delay(150/(spd+1));
      

      
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[j][i], LOW); 
      }
  }

  digitalWrite(cath[5-k], HIGH);
  
  for(int i=5-k;i>=0+k;i--){
      digitalWrite(cath[i], LOW);
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[j][i], HIGH); 
      } 

      
      if(Serial.available()>0)
        spd = Serial.read() - '0';

        delay(150/(spd+1));
      

      
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[j][i], LOW); 
      }
      digitalWrite(cath[i], HIGH);
  }

  digitalWrite(cath[0+k], LOW);

  for(int i=0;i<=5;i++){
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[j][i], HIGH); 
      }

      
      if(Serial.available()>0)
        spd = Serial.read() - '0';

        delay(150/(spd+1));
      

      
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[j][i], LOW); 
      }
  }

  digitalWrite(cath[0+k], HIGH);

  for(int i=5-k;i>=0+k;i--){
      digitalWrite(cath[5-i], LOW);
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[j][i], HIGH); 
      } 

      
      if(Serial.available()>0)
        spd = Serial.read() - '0';

        delay(150/(spd+1));
      

      
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[j][i], LOW); 
      }
      digitalWrite(cath[5-i], HIGH);
  }
}
}



for(int k=2;k>=0;k--){
  for(int n=1;n<=2;n++){
  digitalWrite(cath[5-k], LOW);
  
  for(int i=0+k;i<=5-k;i++){
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[i][j], HIGH); 
      }

      
      if(Serial.available()>0)
        spd = Serial.read() - '0';

        delay(150/(spd+1));
      

      
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[i][j], LOW); 
      }
  }

  digitalWrite(cath[5-k], HIGH);
  
  for(int i=5-k;i>=0+k;i--){
      digitalWrite(cath[i], LOW);
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[i][j], HIGH); 
      } 

      
      if(Serial.available()>0)
        spd = Serial.read() - '0';

        delay(150/(spd+1));
      

      
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[i][j], LOW); 
      }
      digitalWrite(cath[i], HIGH);
  }

  digitalWrite(cath[0+k], LOW);

  for(int i=0;i<=5;i++){
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[i][j], HIGH); 
      }
      
      if(Serial.available()>0)
        spd = Serial.read() - '0';

        delay(150/(spd+1));
      
      
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[i][j], LOW); 
      }
  }

  digitalWrite(cath[0+k], HIGH);

  for(int i=5-k;i>=0+k;i--){
      digitalWrite(cath[5-i], LOW);
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[i][j], HIGH); 
      } 
      if(Serial.available()>0)
        spd = Serial.read() - '0';

        delay(150/(spd+1));
      
      
      for(int j=0+k;j<=5-k;j++){
        digitalWrite(an[i][j], LOW); 
      }
      digitalWrite(cath[5-i], HIGH);
  }
}
}


}


////////////////////////////////////////////////////////////



  goto again;
}




void setup() 
{
  Serial.begin(9600);
  Serial.setTimeout(2);

  //random seed
  randomSeed(analogRead(0));

  
  //output pins : cathode
  for(int i=0;i<6;i++)
  {
    pinMode(cath[i], OUTPUT);
  }

  //output pins : anode
  for(int i=0;i<6;i++)
  {
    for(int j=0;j<6;j++)
    {
      pinMode(an[i][j], OUTPUT);
    }
  }
  for(int i=0;i<6;i++)
  {
    digitalWrite(cath[i], HIGH);
  }
}



void loop() 
{
  intro();
  start:
  while(Serial.available()==0);
  String str = "";
  if(Serial.available()>0)
  {
    str = Serial.readString();
  }

  if(str == "snake")
  {
    runSnake();
  }
  else if(str == "shoot")
  {
    runShoot();
  }
  else if(str == "graph")
  {
    runGraph();
  }
  else if(str == "beat")
  {
    runBeat();
  }
  goto start;
}
