void informationBits()
{

   //format & version information fields
   for(int i = 210; i > 140; i-=10){
      if(TypeInfomationBits[counter] == 1){
        Tft.fillRectangle(i,170,10,10,BLACK);
      }else{
        Tft.fillRectangle(i,170,10,10,WHITE);
      } 
     counter += 1;
   }

   for(int i = 120; i > 40; i-=10){
     if(TypeInfomationBits[counter] == 1){
       Tft.fillRectangle(90,i,10,10,BLACK);
     }else{
       Tft.fillRectangle(90,i,10,10,WHITE);
     }
     counter += 1;  
   }

   //Clear counter to display information bits again
   counter = 0;
  
   for(int i = 250; i > 190; i-=10){
     if(TypeInfomationBits[counter] == 1){
       Tft.fillRectangle(90,i,10,10,BLACK);
     }else{
       Tft.fillRectangle(90,i,10,10,WHITE);
     }
     counter += 1;       
   }
   
   if(TypeInfomationBits[counter] == 1){
     Tft.fillRectangle(90,180,10,10,BLACK);
   }else{
     Tft.fillRectangle(90,180,10,10,WHITE);
   }
   counter += 1; 
   
    if(TypeInfomationBits[counter] == 1){
     Tft.fillRectangle(90,170,10,10,BLACK);
   }else{
     Tft.fillRectangle(90,170,10,10,WHITE);
   }
   counter += 1; 
   
  if(TypeInfomationBits[counter] == 1){
     Tft.fillRectangle(80,170,10,10,BLACK);
   }else{
     Tft.fillRectangle(80,170,10,10,WHITE);
   }
   counter += 1; 
  
   for(int i = 60; i > 0; i-=10){
     if(TypeInfomationBits[counter] == 1){
       Tft.fillRectangle(i,170,10,10,BLACK);
     }else{
       Tft.fillRectangle(i,170,10,10,WHITE);
     }
     counter += 1;      
   }

   //end format & version 
   //clear counter for message bits
   counter = 0;
   
  //Write Data Bits
  //up  
  for(int xPos = 210; xPos > 90; xPos-=10){
    for(int yPos = 50; yPos < 70; yPos+=10){
      getXY(xPos, yPos);
      int mask = (y + x) % 2;
        if(mask == 0){
          if(BinaryMessage[counter] == 1){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,WHITE);
          } 
          if(BinaryMessage[counter] == 0){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,BLACK);
          }
        }else if(mask == 1){
          if(BinaryMessage[counter] == 1){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,BLACK);
          } 
          if(BinaryMessage[counter] == 0){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,WHITE);
          }     
        }
      counter += 1;  
    }
  }




  //down
  for(int xPos = 100; xPos < 220; xPos +=10){
    for(int yPos = 70; yPos < 90; yPos+=10){
      getXY(xPos, yPos);
      int mask = (y + x) % 2;
        if(mask == 0){
          if(BinaryMessage[counter] == 1){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,WHITE);
          } 
          if(BinaryMessage[counter] == 0){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,BLACK);
          }
        }else if(mask == 1){
          if(BinaryMessage[counter] == 1){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,BLACK);
          } 
          if(BinaryMessage[counter] == 0){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,WHITE);
          }     
        }
      counter += 1;  

    }
  }
  
  
  //up
  for(int xPos = 210; xPos > 90; xPos-=10){
    for(int yPos = 90; yPos < 110; yPos+=10){
      getXY(xPos, yPos);
      int mask = (y + x) % 2;
        if(mask == 0){
          if(BinaryMessage[counter] == 1){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,WHITE);
          } 
          if(BinaryMessage[counter] == 0){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,BLACK);
          }
        }else if(mask == 1){
          if(BinaryMessage[counter] == 1){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,BLACK);
          } 
          if(BinaryMessage[counter] == 0){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,WHITE);
          }     
        }
      counter += 1;        
      
    }
  }


  //down
  for(int xPos = 100; xPos < 220; xPos +=10){
    for(int yPos = 110; yPos < 130; yPos+=10){
      getXY(xPos, yPos);
      int mask = (y + x) % 2;
        if(mask == 0){
          if(BinaryMessage[counter] == 1){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,WHITE);
          } 
          if(BinaryMessage[counter] == 0){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,BLACK);
          }
        }else if(mask == 1){
          if(BinaryMessage[counter] == 1){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,BLACK);
          } 
          if(BinaryMessage[counter] == 0){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,WHITE);
          }     
        }
      counter += 1;          
    }
  }


  //up
  for(int xPos = 210; xPos > 170; xPos-=10){
    for(int yPos = 130; yPos < 150; yPos+=10){
      getXY(xPos, yPos);
      int mask = (y + x) % 2;
        if(mask == 0){
          if(BinaryMessage[counter] == 1){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,WHITE);
          } 
          if(BinaryMessage[counter] == 0){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,BLACK);
          }
        }else if(mask == 1){
          if(BinaryMessage[counter] == 1){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,BLACK);
          } 
          if(BinaryMessage[counter] == 0){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,WHITE);
          }     
        }
      counter += 1;          
    
    }
  }

  
  //Clear counter to begin ECC Bits
  counter = 0;
  //continue up
  for(int xPos = 170; xPos > 70; xPos-=10){
    for(int yPos = 130; yPos < 150; yPos+=10){
      getXY(xPos, yPos);
      int mask = (y + x) % 2;
        if(mask == 0){
          if(BinaryECCWords[counter] == 1){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,WHITE);
          } 
          if(BinaryECCWords[counter] == 0){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,BLACK);
          }
        }else if(mask == 1){
          if(BinaryECCWords[counter] == 1){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,BLACK);
          } 
          if(BinaryECCWords[counter] == 0){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,WHITE);
          }     
        }
      counter += 1;          
    
    }
  }
  
  
    //skip over timing pattern
  //up
  for(int xPos = 60; xPos > 0; xPos-=10){
    for(int yPos = 130; yPos < 150; yPos+=10){
      getXY(xPos, yPos);
      int mask = (y + x) % 2;
        if(mask == 0){
          if(BinaryECCWords[counter] == 1){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,WHITE);
          } 
          if(BinaryECCWords[counter] == 0){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,BLACK);
          }
        }else if(mask == 1){
          if(BinaryECCWords[counter] == 1){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,BLACK);
          } 
          if(BinaryECCWords[counter] == 0){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,WHITE);
          }     
        }
      counter += 1;     
    }
  }
  
  
    //down
  for(int xPos = 10; xPos < 70; xPos +=10){
    for(int yPos = 150; yPos < 170; yPos+=10){
      getXY(xPos, yPos);
      int mask = (y + x) % 2;
        if(mask == 0){
          if(BinaryECCWords[counter] == 1){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,WHITE);
          } 
          if(BinaryECCWords[counter] == 0){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,BLACK);
          }
        }else if(mask == 1){
          if(BinaryECCWords[counter] == 1){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,BLACK);
          } 
          if(BinaryECCWords[counter] == 0){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,WHITE);
          }     
        }
      counter += 1;     
    }
  }
  
  //skip over timing pattern
  //down
  for(int xPos = 80; xPos < 220; xPos +=10){
    for(int yPos = 150; yPos < 170; yPos+=10){
      getXY(xPos, yPos);
      int mask = (y + x) % 2;
        if(mask == 0){
          if(BinaryECCWords[counter] == 1){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,WHITE);
          } 
          if(BinaryECCWords[counter] == 0){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,BLACK);
          }
        }else if(mask == 1){
          if(BinaryECCWords[counter] == 1){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,BLACK);
          } 
          if(BinaryECCWords[counter] == 0){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,WHITE);
          }     
        }
      counter += 1;     
    }
  }
      
      
  //up
  for(int xPos = 130; xPos > 90; xPos-=10){
    for(int yPos = 170; yPos < 190; yPos+=10){  
      getXY(xPos, yPos);
      int mask = (y + x) % 2;
        if(mask == 0){
          if(BinaryECCWords[counter] == 1){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,WHITE);
          } 
          if(BinaryECCWords[counter] == 0){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,BLACK);
          }
        }else if(mask == 1){
          if(BinaryECCWords[counter] == 1){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,BLACK);
          } 
          if(BinaryECCWords[counter] == 0){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,WHITE);
          }     
        }
      counter += 1;     
    }
  }   
      
      
  //down
  for(int xPos = 100; xPos < 140; xPos +=10){
    for(int yPos = 200; yPos < 220; yPos+=10){ 
      getXY(xPos, yPos);
      int mask = (y + x) % 2;
        if(mask == 0){
          if(BinaryECCWords[counter] == 1){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,WHITE);
          } 
          if(BinaryECCWords[counter] == 0){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,BLACK);
          }
        }else if(mask == 1){
          if(BinaryECCWords[counter] == 1){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,BLACK);
          } 
          if(BinaryECCWords[counter] == 0){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,WHITE);
          }     
        }
      counter += 1;     
    }
  }   



  //up
  for(int xPos = 130; xPos > 90; xPos-=10){
    for(int yPos = 220; yPos < 240; yPos+=10){  
      getXY(xPos, yPos);
      int mask = (y + x) % 2;
        if(mask == 0){
          if(BinaryECCWords[counter] == 1){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,WHITE);
          } 
          if(BinaryECCWords[counter] == 0){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,BLACK);
          }
        }else if(mask == 1){
          if(BinaryECCWords[counter] == 1){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,BLACK);
          } 
          if(BinaryECCWords[counter] == 0){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,WHITE);
          }     
        }
      counter += 1;     
    }
  }
  
  //down
  for(int xPos = 100; xPos < 140; xPos +=10){
    for(int yPos = 240; yPos < 260; yPos+=10){ 
      getXY(xPos, yPos);
      int mask = (y + x) % 2;
        if(mask == 0){
          if(BinaryECCWords[counter] == 1){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,WHITE);
          } 
          if(BinaryECCWords[counter] == 0){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,BLACK);
          }
        }else if(mask == 1){
          if(BinaryECCWords[counter] == 1){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,BLACK);
          } 
          if(BinaryECCWords[counter] == 0){
            //Do oposite
            Tft.fillRectangle(xPos,yPos,10,10,WHITE);
          }     
        }
      counter += 1;     
    }
  }  
   
  counter = 0;
      
}

void getXY(int x1, int y1)
{
   if(y1 == 50){
     x = 1; 
   }
   if(y1 == 60){
     x = 2; 
   }
   if(y1 == 70){
     x = 3; 
   }
   if(y1 == 80){
     x = 4; 
   }   
   if(y1 == 90){
     x = 5; 
   }  
   if(y1 == 100){
     x = 6; 
   }  
   if(y1 == 110){
     x = 7; 
   }  
   if(y1 == 120){
     x = 8; 
   } 
   if(y1 == 130){
     x = 9; 
   }    
   if(y1 == 140){
     x = 10; 
   }  
   if(y1 == 150){
     x = 11; 
   } 
   if(y1 == 160){
     x = 12; 
   } 
   if(y1 == 170){
     x = 13; 
   } 
   if(y1 == 180){
     x = 14; 
   } 
   if(y1 == 190){
     x = 15; 
   }    
   if(y1 == 200){
     x = 16; 
   } 
   if(y1 == 210){
     x = 17; 
   } 
   if(y1 == 220){
     x = 18; 
   } 
   if(y1 == 230){
     x = 19; 
   }
   if(y1 == 240){
     x = 20; 
   }   
   if(y1 == 250){
     x = 21; 
   }  
   
   
   if(x1 == 210){
     y = 1; 
   }
   
   if(x1 == 200){
     y = 2; 
   }
   if(x1 == 190){
     y = 3; 
   }
   
   if(x1 == 180){
     y = 4; 
   }
   if(x1 == 170){
     y = 5; 
   } 

   if(x1 == 160){
     y = 6; 
   }
   if(x1 == 150){
     y = 7; 
   } 
   
   if(x1 == 140){
     y = 8; 
   }
   
   if(x1 == 130){
     y = 9; 
   }
   
   if(x1 == 120){
     y = 10; 
   }
   
   if(x1 == 110){
     y = 11; 
   }
   if(x1 == 100){
     y = 12; 
   } 

   if(x1 == 90){
     y = 13; 
   }
   
   if(x1 == 80){
     y = 14; 
   } 
   
  if(x1 == 70){
     y = 15; 
   } 

  if(x1 == 60){
     y = 16; 
   } 
   
     if(x1 == 50){
     y = 17; 
   } 
   
  if(x1 == 40){
     y = 18; 
   } 
   
  if(x1 == 30){
     y = 19; 
   }  
 
   if(x1 == 20){
     y = 20; 
   } 
 
   if(x1 == 10){
     y = 21; 
   }   
   
}

