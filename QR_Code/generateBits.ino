void calculateQRCode()
{
  //Initialize varaibles
  eccBinary = "";
  dataString = "";
  byteMessage = "";
  messageToEncode = "HACKADAY";
  length = 0;
  byteCounter = 0;
  exponent = 25;
  zeroFound = false;

  //Set Datamode bits to 1 for alphanumic
  setDataModeBits(1);
  if(debug){
    Serial.println("------------------------ Step 1 ------------------------ ");
    Serial.println("Set data mode to : Alphanumeric");
    Serial.println("Sending type bits (4) to output ...");
    Serial.print("Sent 4 bits of output: ");
    Serial.println(dataString);  
    Serial.println("------------------------ Step 2 ------------------------ ");
    Serial.println("Encode length of data.");
    Serial.println("Calculating bit size for data length ..");
    Serial.println("QR Type: Alphanumeric, QR Version 1, Bit Size: 9 bits.");
  }
  //Encode length of data
  encodeDataLength();
  if(debug){
    Serial.print("Data stored in output : ");
    Serial.println(dataString);
    Serial.println("------------------------ Step 3 ------------------------ ");
    Serial.println("Encode Data to Binary");
    Serial.println("Writing characters ..");
  }
  //Endcode Data in binary
  encodeData();
  if(debug){
    Serial.println("Input successfully encoded to binary.");
    Serial.println("------------------------ Step 4 ------------------------ ");
    Serial.println("Finishing binary string...");
  }
  //Terminate the bits
  terminateBits();
  if(debug){
    Serial.println("------------------------ Step 5 ------------------------ ");
    Serial.println("Dividing bits into bytes (8 bits per byte)...");
  }
  //Delimit the string into 8-bit words, then pad with 0's if necessary
  delimitBitstoBytes();
  if(debug){
    Serial.println("------------------------ Step 6 ------------------------ ");
    Serial.println("Inserting characters to fill missing data string...");
  }
  //Add words at end of string if less than 104 bit's or 13 8-bit words
  addWord();
  if(debug){
    Serial.println("------------------------ Step 7 ------------------------ ");
    Serial.println("Calculating error code correction...");
  }
  //Convert each 8-bit word from binary to decmil
  decimal();
  //Convert & store decimal Message to Alpha Notation
  messageToAlpha();
  //Generate ECC words
  ecc();
  //Convert & Store ECC Words in binary to eccBinary
  for(int h = 0; h < 13; h++){    
    //Convert to binary and append to eccBinary
    for(int j = 8-1; j > -1; j--){
      eccBinary += bitRead(Result[h], j);
    }
  } 
  //Take the binary message and store in BinaryMessage array
  for(int i = 0; i < 104; i++){
    BinaryMessage[i] = byteMessage.charAt(i) - '0';
  } 
  //Take the ecc binary data and store in BinaryECCWords array
  for(int i = 0; i < 104; i++){
    BinaryECCWords[i] = eccBinary.charAt(i) - '0';
  } 
 
  if(debug){
    Serial.println("------------------------ ECC Words ------------------------ ");
    for(int i = 0; i < 13; i++){
      Serial.print(Result[i]);
      Serial.print(" ");
    }  
    Serial.println();
     
    Serial.println("------------------------ Binary Data ------------------------ ");
    Serial.println("Binary Message : ");
    Serial.println(byteMessage);
    Serial.println("Binary ECC Words : ");
    Serial.println(eccBinary);
  } 
 
}

void setDataModeBits(int datamode)
{
 switch(datamode)
 {
   //numeric
  case 0:
    dataString += "0001";
    break;
  case 1:
    //alphanumeric
    dataString += "0010";
    break; 
 }
}

void encodeDataLength()
{
  length = messageToEncode.length();

  //Insert Padding for 9 bit
  dataString += "0000";

  for(int i = 4; i > -1; i--){
    dataString += bitRead(length, i);  
  }
}

void encodeData()
{
  int numArray[20];
  int totalArray[20];
  char charBuffer[20] = {};
  int numBits = 0;
    
  /*Read the String messageToEncode 2 characters at a time
    Convert characters to ASCII & then perform some arthmitic
    Store the result in totalArray which will then get converted
    to binary and appended to dataString.
  */

  //If the length of the message is even 
  if (length == 2  || length == 4 || length == 6 || length == 8 || length == 10 ||  length == 12 || length == 14 || length == 16){
    for (int i = 0; i < length; i+=2){
      //First Character
      charBuffer[i] = messageToEncode.charAt(i);
      //Second Character
      charBuffer[i+1] = messageToEncode.charAt(i+1);
      //If the character is a number convert it to an int
      if(isDigit(charBuffer[i])) {
        numArray[i] = charBuffer[i] - '0';
      }
      //If the character is punctuation I assume it found : & force the value 44. 
      //ASCII values in arduino seems to differ slightly from QR code ASCII
      if(isPunct(charBuffer[i])) {
        numArray[i] = 44;
      }
      //If the character is a space force the value 36
      if(isSpace(charBuffer[i])) {
        numArray[i] = 36; 
      }   
      //If the character is alpha numeric
      if(isAlphaNumeric(charBuffer[i])){
        if(charBuffer[i] == 'A')
          numArray[i] = 10;
        if(charBuffer[i] == 'B')
          numArray[i] = 11;
        if(charBuffer[i] == 'C')
          numArray[i] = 12;
        if(charBuffer[i] == 'D')
          numArray[i] = 13;
        if(charBuffer[i] == 'E')
          numArray[i] = 14;
        if(charBuffer[i] == 'F')
          numArray[i] = 15;
        if(charBuffer[i] == 'G')
          numArray[i] = 16;
        if(charBuffer[i] == 'H')
          numArray[i] = 17;
        if(charBuffer[i] == 'I')
          numArray[i] = 18;
        if(charBuffer[i] == 'J')
          numArray[i] = 19;
        if(charBuffer[i] == 'K')
          numArray[i] = 20;
        if(charBuffer[i] == 'L')
          numArray[i] = 21;
        if(charBuffer[i] == 'M')
          numArray[i] = 22;
        if(charBuffer[i] == 'N')
          numArray[i] = 23;
        if(charBuffer[i] == 'O')
          numArray[i] = 24;
        if(charBuffer[i] == 'P')
          numArray[i] = 25;
        if(charBuffer[i] == 'Q')
          numArray[i] = 26;
        if(charBuffer[i] == 'R')
          numArray[i] = 27;
        if(charBuffer[i] == 'S')
          numArray[i] = 28;
        if(charBuffer[i] == 'T')
          numArray[i] = 29;
        if(charBuffer[i] == 'U')
          numArray[i] = 30;
        if(charBuffer[i] == 'V')
          numArray[i] = 31;
        if(charBuffer[i] == 'W')
          numArray[i] = 32;
        if(charBuffer[i] == 'X')
          numArray[i] = 33;
        if(charBuffer[i] == 'Y')
          numArray[i] = 34;
        if(charBuffer[i] == 'Z')
          numArray[i] = 35;
      }
      //If the character is a number convert it to an int  
      if(isDigit(charBuffer[i+1])) {
        numArray[i+1] = charBuffer[i+1] - '0';
      }
      //If the character is punctuation I assume it found : & force the value 44. 
      //ASCII values in arduino seems to differ slightly from QR code ASCII
      if(isPunct(charBuffer[i+1])) {
        numArray[i+1] = 44;
      }  
      //If the character is a space force the value 36
      if(isSpace(charBuffer[i+1])) {
        numArray[i+1] = 36; 
      }
      //If the character is alpha numeric
      if(isAlphaNumeric(charBuffer[i+1])){
        if(charBuffer[i+1] == 'A')
          numArray[i+1] = 10;
        if(charBuffer[i+1] == 'B')
          numArray[i+1] = 11;
        if(charBuffer[i+1] == 'C')
          numArray[i+1] = 12;
        if(charBuffer[i+1] == 'D')
          numArray[i+1] = 13;
        if(charBuffer[i+1] == 'E')
          numArray[i+1] = 14;
        if(charBuffer[i+1] == 'F')
          numArray[i+1] = 15;
        if(charBuffer[i+1] == 'G')
          numArray[i+1] = 16;
        if(charBuffer[i+1] == 'H')
          numArray[i+1] = 17;
        if(charBuffer[i+1] == 'I')
          numArray[i+1] = 18;
        if(charBuffer[i+1] == 'J')
          numArray[i+1] = 19;
        if(charBuffer[i+1] == 'K')
          numArray[i+1] = 20;
        if(charBuffer[i+1] == 'L')
          numArray[i+1] = 21;
        if(charBuffer[i+1] == 'M')
          numArray[i+1] = 22;
        if(charBuffer[i+1] == 'N')
          numArray[i+1] = 23;
        if(charBuffer[i+1] == 'O')
          numArray[i+1] = 24;
        if(charBuffer[i+1] == 'P')
          numArray[i+1] = 25;
        if(charBuffer[i+1] == 'Q')
          numArray[i+1] = 26;
        if(charBuffer[i+1] == 'R')
          numArray[i+1] = 27;
        if(charBuffer[i+1] == 'S')
          numArray[i+1] = 28;
        if(charBuffer[i+1] == 'T')
          numArray[i+1] = 29;
        if(charBuffer[i+1] == 'U')
          numArray[i+1] = 30;
        if(charBuffer[i+1] == 'V')
          numArray[i+1] = 31;
        if(charBuffer[i+1] == 'W')
          numArray[i+1] = 32;
        if(charBuffer[i+1] == 'X')
          numArray[i+1] = 33;
        if(charBuffer[i+1] == 'Y')
          numArray[i+1] = 34;
        if(charBuffer[i+1] == 'Z')
          numArray[i+1] = 35;          
      }
      //Perform the necessay arthmitic & store the result in totalArray
      //Later each value in the array will be converted to its binary equevillant
      totalArray[i] = (45 * numArray[i]) + numArray[i+1];
     
      if (debug) {
        //Print the output in a readable manor            
        Serial.print("- Characters: ");
        Serial.print(charBuffer[i]);
        Serial.print(", ");
        Serial.print(charBuffer[i+1]);
        Serial.print(": (45 * ");
        Serial.print(numArray[i]);
        Serial.print(") + ");
        Serial.print(numArray[i+1]);
        Serial.print(" = ");
        Serial.print(totalArray[i]);
        Serial.println();
      }        
    }

    //take the contents of totalArray & convert to binary append  to dataString
    for(int h = 0; h < length; h+=2){
      //You need 11 bit binay results so there is no reason to 
      //determine binary output size
      for(int j = 11-1; j > -1; j--){
        dataString += bitRead(totalArray[h], j);
      }
    }

  }
  
  //If the message length is odd
  if (length == 1  || length == 3 || length == 5 || length == 7 || length == 9 ||  length == 11 || length == 13 || length == 15){
    //Remove the last character that way it can 
    for (int i = 0; i < length-1; i+=2){
      //First Character
      charBuffer[i] = messageToEncode.charAt(i);
      //Second Character
      charBuffer[i+1] = messageToEncode.charAt(i+1);
      //If the character is a number convert it to an int
      if(isDigit(charBuffer[i])) {
        numArray[i] = charBuffer[i] - '0';
      }
      //If the character is punctuation I assume it found : & force the value 44. 
      //ASCII values in arduino seems to differ slightly from QR code ASCII
      if(isPunct(charBuffer[i])) {
        numArray[i] = 44;
      }
      //If the character is a space force the value 36
      if(isSpace(charBuffer[i])) {
        numArray[i] = 36; 
      }   
      //If the character is alpha numeric
      if(isAlphaNumeric(charBuffer[i])){
        if(charBuffer[i] == 'A')
          numArray[i] = 10;
        if(charBuffer[i] == 'B')
          numArray[i] = 11;
        if(charBuffer[i] == 'C')
          numArray[i] = 12;
        if(charBuffer[i] == 'D')
          numArray[i] = 13;
        if(charBuffer[i] == 'E')
          numArray[i] = 14;
        if(charBuffer[i] == 'F')
          numArray[i] = 15;
        if(charBuffer[i] == 'G')
          numArray[i] = 16;
        if(charBuffer[i] == 'H')
          numArray[i] = 17;
        if(charBuffer[i] == 'I')
          numArray[i] = 18;
        if(charBuffer[i] == 'J')
          numArray[i] = 19;
        if(charBuffer[i] == 'K')
          numArray[i] = 20;
        if(charBuffer[i] == 'L')
          numArray[i] = 21;
        if(charBuffer[i] == 'M')
          numArray[i] = 22;
        if(charBuffer[i] == 'N')
          numArray[i] = 23;
        if(charBuffer[i] == 'O')
          numArray[i] = 24;
        if(charBuffer[i] == 'P')
          numArray[i] = 25;
        if(charBuffer[i] == 'Q')
          numArray[i] = 26;
        if(charBuffer[i] == 'R')
          numArray[i] = 27;
        if(charBuffer[i] == 'S')
          numArray[i] = 28;
        if(charBuffer[i] == 'T')
          numArray[i] = 29;
        if(charBuffer[i] == 'U')
          numArray[i] = 30;
        if(charBuffer[i] == 'V')
          numArray[i] = 31;
        if(charBuffer[i] == 'W')
          numArray[i] = 32;
        if(charBuffer[i] == 'X')
          numArray[i] = 33;
        if(charBuffer[i] == 'Y')
          numArray[i] = 34;
        if(charBuffer[i] == 'Z')
          numArray[i] = 35;
      }
      //If the character is a number convert it to an int  
      if(isDigit(charBuffer[i+1])) {
        numArray[i+1] = charBuffer[i+1] - '0';
      }
      //If the character is punctuation I assume it found : & force the value 44. 
      //ASCII values in arduino seems to differ slightly from QR code ASCII
      if(isPunct(charBuffer[i+1])) {
        numArray[i+1] = 44;
      }  
      //If the character is a space force the value 36
      if(isSpace(charBuffer[i+1])) {
        numArray[i+1] = 36; 
      }
      //If the character is alpha numeric
      if(isAlphaNumeric(charBuffer[i+1])){
        if(charBuffer[i+1] == 'A')
          numArray[i+1] = 10;
        if(charBuffer[i+1] == 'B')
          numArray[i+1] = 11;
        if(charBuffer[i+1] == 'C')
          numArray[i+1] = 12;
        if(charBuffer[i+1] == 'D')
          numArray[i+1] = 13;
        if(charBuffer[i+1] == 'E')
          numArray[i+1] = 14;
        if(charBuffer[i+1] == 'F')
          numArray[i+1] = 15;
        if(charBuffer[i+1] == 'G')
          numArray[i+1] = 16;
        if(charBuffer[i+1] == 'H')
          numArray[i+1] = 17;
        if(charBuffer[i+1] == 'I')
          numArray[i+1] = 18;
        if(charBuffer[i+1] == 'J')
          numArray[i+1] = 19;
        if(charBuffer[i+1] == 'K')
          numArray[i+1] = 20;
        if(charBuffer[i+1] == 'L')
          numArray[i+1] = 21;
        if(charBuffer[i+1] == 'M')
          numArray[i+1] = 22;
        if(charBuffer[i+1] == 'N')
          numArray[i+1] = 23;
        if(charBuffer[i+1] == 'O')
          numArray[i+1] = 24;
        if(charBuffer[i+1] == 'P')
          numArray[i+1] = 25;
        if(charBuffer[i+1] == 'Q')
          numArray[i+1] = 26;
        if(charBuffer[i+1] == 'R')
          numArray[i+1] = 27;
        if(charBuffer[i+1] == 'S')
          numArray[i+1] = 28;
        if(charBuffer[i+1] == 'T')
          numArray[i+1] = 29;
        if(charBuffer[i+1] == 'U')
          numArray[i+1] = 30;
        if(charBuffer[i+1] == 'V')
          numArray[i+1] = 31;
        if(charBuffer[i+1] == 'W')
          numArray[i+1] = 32;
        if(charBuffer[i+1] == 'X')
          numArray[i+1] = 33;
        if(charBuffer[i+1] == 'Y')
          numArray[i+1] = 34;
        if(charBuffer[i+1] == 'Z')
          numArray[i+1] = 35;          
      }

      //Perform the necessay arthmitic & store the result in totalArray
      //Later each value in the array will be converted to its binary equevillant
      totalArray[i] = (45 * numArray[i]) + numArray[i+1];

      if (debug) {
        //Print the output in a readable manor            
        Serial.print("- Characters: ");
        Serial.print(charBuffer[i]);
        Serial.print(", ");
        Serial.print(charBuffer[i+1]);
        Serial.print(": (45 * ");
        Serial.print(numArray[i]);
        Serial.print(") + ");
        Serial.print(numArray[i+1]);
        Serial.print(" = ");
        Serial.print(totalArray[i]);
        Serial.println();
      }                 
    }
  
    //take the contents of totalArray & convert to binary append  to dataString
    for(int h = 0; h < length-1; h+=2){
      //You need 11 bit binay results so there is no reason to 
      //determine binary output size
      for(int j = 11-1; j > -1; j--){
        dataString += bitRead(totalArray[h], j);
      }
    }
  
  
   //Take the last character & convert it into a 6 bit binary representation then append to dataString
   for(int j = 6-1; j > -1; j--){
     dataString += bitRead(totalArray[length], j);
   }
   Serial.println("Message was odd last character encoded as 6 bit binary.");
  }  
  
  
  

}

void terminateBits()
{
 int totalLength = dataString.length(); 
 if(totalLength+4 < 104){
   if(debug){
     Serial.print("Maxium bits for current version : 104 current bits: ");
     Serial.println(totalLength);   
   }
   dataString += "0000"; 
   if (debug){
     Serial.print("Added 4 bits to binary output. Total : ");
     Serial.println(dataString.length());  
   }
 }
}

void delimitBitstoBytes()
{
  int stringSize = dataString.length();
  //Delimit dataString into 8 bit bytes & store in char array or something similar
  //I cant think of a good reason I would have to store it in a binary array
  //If final byte < 8 bits pad the ending with zeros
  for(int k = 0; k < stringSize; k+=8){

    int byteSize = dataString.substring(k, k + 8).length();
    if(byteSize == 8){
      byteMessage += dataString.substring(k, k + 8);
      
    }else if(byteSize < 8){
      int bitDifference = 8 - byteSize;

      byteMessage += dataString.substring(k, k + 8);

      for(int i = 0; i < bitDifference;i++){
        byteMessage += '0';
      }
    }
  }
  
  for(int k = 0; k < stringSize; k+=8){
    //Serial.println(byteMessage.substring(k, k + 8));
    byteCounter += 1;
  }

}

void addWord()
{
 if(debug){
   Serial.print("Current output size : ");  
   Serial.print(byteCounter);
   Serial.print(", missing: ");
 }
 int byteDifference = 13 - byteCounter;
 if(debug){
   Serial.print(byteDifference);
   Serial.print(" bytes.");
   Serial.println();
   Serial.print("Added bytes: ");  
 }

 for(int i = 0; i < byteDifference; i++){
   if(i == 0 || i == 2 || i == 4 || i == 6 || i == 8 || i == 10 || i == 12){
     if(debug){
       Serial.print(" 236 ");  
     }
     byteMessage += "11101100";
     byteCounter += 1;
   }
   if(i == 1 || i == 3 || i == 5 || i == 6 || i == 9 || i == 11 || i == 13){
     if(debug){
       Serial.print(" 17 ");  
     }
     byteMessage += "00010001"; 
     byteCounter += 1;
   }
 }
  
 if(debug){
   Serial.println();
   Serial.print("Output size filled to match data size: ");
   Serial.print(byteCounter);
   Serial.println("/13 bytes");
 } 
  
  
}

void decimal()
{
  
  if(debug){
    Serial.println("Dividing message into 8 bit binary segments");
    Serial.println("Creating message polynomial for each block.");
    Serial.println("-------------------------------------------------------- ");
    Serial.println("Message Polynomial :");
  }
  
  int stringSize = byteMessage.length(); 

  int counter = 0;  

  for(int k = 0; k < stringSize; k+=8){
    String binary = byteMessage.substring(k, k + 8);
    MessageI[counter] = binaryToDecimal(binary);
    counter += 1;
  }
 
 if(debug){
   //Display polynomial
  for(int i = 0; i < 13; i++){
    if(i == 6 || i == 12){
      Serial.println();
    }
    Serial.print("(");
    Serial.print(MessageI[i]); 
    Serial.print("x ^ "); 
    Serial.print(exponent-i);
    if(i < 12){
      Serial.print(") + ");
    }else{
      Serial.print(")");
    }
  }
  Serial.println();
 } 
  
}

int binaryToDecimal(String bits)
{
  char charBuffer[8];
  int numArray[8] = {};
  
  for(int i = 0; i < 8; i++){
    charBuffer[i] = bits.charAt(i);
    numArray[i] = charBuffer[i] - '0';
  }

  return (numArray[0] * pow(2, 7)) + (numArray[1] * pow(2, 6)) + (numArray[2] * pow(2, 5)) + (numArray[3] * pow(2, 4)) + (numArray[4] * pow(2, 3)) +(numArray[5] * pow(2, 2)) + (numArray[6] * pow(2, 1)) + (numArray[7] * pow(2, 0)); 
}

void messageToAlpha()
{
  for(int i = 0; i < 13; i++){
    int x = MessageI[i];
    x -= 1;
    MessageA[i] = LogTable[x][3]; 
  }
  
}

void ecc()
{ 
  
 //Add exponents 
 for(int i = 0; i < 14; i++){
   Result[i] = MessageA[0] + GeneratorA[i];
 }
 
 //Modulo Result
 for(int i = 0; i < 14; i++){
   if(Result[i] > 255){ 
     Result[i] = Result[i] % 255;
   }
 }
 
 //Convert result from Alpha Notation to Integer Notation
 for(int i = 0; i < 14; i++){
   int x = Result[i];
   x -= 1;
   Result[i] = LogTable[x][1];
 }
 
 //XOR Polynomial
 for(int i = 0; i < 13; i++){
   int x = MessageI[i];
   int y = Result[i];
   Result[i] = x ^ y;
 }
 
 //Loop until last exponent in polynomial is zero
 while(exponent > 13){
    //Remove zeros & decrement exponent
    for(int i = 0; i < 14; i++){
      if(Result[i] == 0){
        zeroFound = true;
        exponent -= 1;
      }
   
      if(zeroFound == true){
        Result[i] = Result[i+1]; 
        xorResult[i] = Result[i];
      }
    }

    
    //Convert result from Integer Notation to Alpha Notation 
    for(int i = 0; i < 13; i++){
      int x = Result[i];
      x -= 1;
      Result[i] = LogTable[x][3];  
    }
    
    //Add Polynomial exponents
    for(int i = 0; i < 14; i++){
      Result[i] = Result[0] + GeneratorA[i];
    }
    
    //Modulo Result
    for(int i = 0; i < 14; i++){
      if(Result[i] > 255){ 
        Result[i] = Result[i] % 255;
      }
    }
    
    //Modulo xorResult
    for(int i = 0; i < 14; i++){
      if(xorResult[i] > 255){ 
        xorResult[i] = xorResult[i] % 255;
      }
    }
    
    //Convert result from Alpha Notation to Integer Notation
    for(int i = 0; i < 14; i++){
      int x = Result[i];
      x -= 1;
      Result[i] = LogTable[x][1];
    }

    
    //XOR Polynomial
    for(int i = 0; i < 14; i++){
      int x = xorResult[i];
      int y = Result[i];
      Result[i] = x ^ y;
    }
  } 
  
  //Remove zeroes without decrementing exponent
  for(int i = 0; i < 13; i++){
  if(Result[i] == 0){
    zeroFound = true;
  }
  
  if(zeroFound == true){
    Result[i] = Result[i+1]; 
    xorResult[i] = Result[i];
  }
 }

}

