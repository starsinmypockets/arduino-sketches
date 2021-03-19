void firstLesson() {  
  char oneChar[] = "a";
  Serial.print(oneChar);
  Serial.print(" sizeof = ");
  Serial.print(sizeof(oneChar));

  char charString[] = "123456789";
  Serial.print(charString);
  Serial.print(" sizeof = ");
  Serial.print(sizeof(charString));
  Serial.print(" strlen= ");
  Serial.print(strlen(charString));

  char charString2[100];
  for (int i = 0; i < sizeof(charString2); i++) {
    charString2[i] = random(32, 126);  
  }
  Serial.println("charString2: ");
  Serial.println(charString2);
  Serial.println(" ");
  Serial.print(" sizeof = ");
  Serial.print(sizeof(charString2));
  Serial.print(" strlen= ");
  Serial.println(strlen(charString2));

  char someString[] = "hello world";
  for (int i = 0; i < sizeof(someString); i++) {
    charString2[i] = someString[i];
  }

  Serial.println("charString2: ");
  Serial.println(charString2);
  Serial.println(strlen(charString2));
}

void secondLesson() {
  char stringOne[20] = "123";  
  char stringTwo[20] = "456";
  Serial.println(stringOne);
  strcat(stringOne, stringTwo);
  Serial.println(stringOne);
  strcat(stringOne, "789");
  Serial.println(stringOne);

  char newString[] = "1234567890";

  if(strlen(stringOne) + strlen(newString) + 1 <= sizeof(stringOne)) {
    strcat(stringOne, newString);
    Serial.println(stringOne);
  } else {
    Serial.println("Error -- toobig");  
  }
}

void thirdLesson() {
  char stringOne[20] = "123";  
  char stringTwo[20] = "456";
  strcpy(stringOne, stringTwo);
  
  Serial.println(stringOne);

  strncpy(stringOne, "abc", sizeof(stringOne));
  strncpy(stringTwo, "def", sizeof(stringTwo));

  strncpy(&stringOne[3], stringTwo, sizeof(stringOne));
  // same as:
  // strncpy(&stringOne[3], &stringTwo[0], sizeof(stringOne));

  Serial.println(stringOne);

  strncpy(stringOne, "abcdef", sizeof(stringOne));
  char abc[20];
  strncpy(abc, stringOne, sizeof(abc));
  abc[3] = NULL;

  char def[20];
  strncpy(def, &stringOne[3], sizeof(def));

  strncpy(stringOne, def, sizeof(stringOne));
  strncpy(&stringOne[3], abc, sizeof(stringOne));

  Serial.println(stringOne);  
}

void fourthLesson() {
   char stringOne[] = "Test string one";
   char stringTwo[] = "Test string two";

   if (strcmp(stringOne, stringTwo) == 0) {
    Serial.println("Equal");
   } else {
    Serial.println("NOT Equal");
   }

}

void fifthLesson() {
  char someData[] = "iohbialzeKevin1234";
  char keyword[] = "Kevin";
  char *pointerToKevin = strstr(someData, keyword);

  if (pointerToKevin != NULL) {
     int position = pointerToKevin - someData;
    Serial.println(position);
    char parsed[20];
    strncpy(parsed, &someData[position + strlen(keyword)], sizeof(parsed));
    Serial.println(parsed); 
  } else {
    Serial.println("NOT FOUND");
  }
}

void sixthLesson() {
  char someData[] = "32yfay98fsay9KevinONE,2,THREE,4,5.2014";
  char keyword[] = "Kevin";
  char *pointerToKevin = strstr(someData, keyword);

  if (pointerToKevin != NULL) {
    int position = pointerToKevin - someData;
    char parsed[50];
    strncpy(parsed, &someData[position + strlen(keyword)], sizeof(parsed));
    char delimiter[] = ",";
    char parsedStrs[5][20];
    char *token = strtok(parsed, delimiter);
    strncpy(parsedStrs[0], token, sizeof(parsedStrs[0]));
    
    for (int i = 1; i < 5; i++) {
      token = strtok(NULL, delimiter);
      strncpy(parsedStrs[i], token, sizeof(parsedStrs[i]));
    }

    for (int i = 0; i < 5; i++) {
      Serial.println(parsedStrs[i]);
    }
    
  } else {
    Serial.println("NOT FOUND");
  }
}

void seventhLesson() {
  char someData[] = "32yfay98fsay9Kevin-56,20000000,4.5677,text,more text";
  char keyword[] = "Kevin";
  char *pointerToKevin = strstr(someData, keyword);

  if (pointerToKevin != NULL) {
    int position = pointerToKevin - someData;
    char parsed[50];
    strncpy(parsed, &someData[position + strlen(keyword)], sizeof(parsed));
    char delimiter[] = ",";
    char parsedStrs[5][20];
    char *token = strtok(parsed, delimiter);
    strncpy(parsedStrs[0], token, sizeof(parsedStrs[0]));
    
    for (int i = 1; i < 5; i++) {
      token = strtok(NULL, delimiter);
      strncpy(parsedStrs[i], token, sizeof(parsedStrs[i]));
    }

    for (int i = 0; i < 5; i++) {
      Serial.println(parsedStrs[i]);
    }

    int firstInt = atoi(parsedStrs[0]);
    long secondLong = atol(parsedStrs[1]);
    float thirdFloat = atof(parsedStrs[2]);
    char newString[100];

    // need to convert float to compile with sprintf
    char floatValue[5];
    dtostrf(thirdFloat, 1, 2, floatValue);
    
    sprintf(newString, "%i, %li, %s, %s, %s", firstInt, secondLong, floatValue, parsedStrs[3], parsedStrs[4]);
    Serial.println(newString);
  } else {
    Serial.println("NOT FOUND");
  }
}

void passString(char *passedStr) {
  Serial.println("Passed str:");
  Serial.println(passedStr);
}

char *returnedStr() {
  return "A string returns";  
}

char eighthLesson() {
  char aString[] = "Hear me roar.";

  passString(aString);

  char newString[20];
  strncpy(newString, returnedStr(), sizeof(newString));
  Serial.println("New string:");
  Serial.println(newString);
}

void ninethLesson() {
  char rawData[100];
  char keyword[] = "myData=";
  Serial.println("Send data as 'myData=text,int,long,float");

  while (1) {
    if (Serial.available() > 0) {
      size_t byteCount = Serial.readBytesUntil('\n', rawData, sizeof(rawData) - 1);
      rawData[byteCount] = NULL; // add terminating null char to raw data string
      Serial.println("Raw data = ");
      Serial.println(rawData);

      char keyword[] = "myData=";
      char *pointerToKw = strstr(rawData, keyword);

    if (pointerToKw != NULL) {
      int position = pointerToKw - rawData;
      char parsed[100];
      strncpy(parsed, &rawData[position + strlen(keyword)], sizeof(parsed));
      char delimiter[] = ",";
      char parsedStrs[4][20];
      char *token = strtok(parsed, delimiter);
      strncpy(parsedStrs[0], token, sizeof(parsedStrs[0]));
    
      for (int i = 1; i < 4; i++) {
        token = strtok(NULL, delimiter);
        strncpy(parsedStrs[i], token, sizeof(parsedStrs[i]));
      }

      for (int i = 0; i < 4; i++) {
        Serial.println(parsedStrs[i]);
      }

      char* first = parsedStrs[0];
      int second = atoi(parsedStrs[1]);
      long third = atol(parsedStrs[2]);
      float fourth = atof(parsedStrs[2]);
      char newString[100];

      // need to convert float to compile with sprintf
      char floatValue[5];
      dtostrf(fourth, 1, 2, floatValue);
      Serial.println(first);
      Serial.println(second);
      Serial.println(third);
      Serial.println(fourth);
      Serial.println(floatValue);
      
      sprintf(newString, "%s, %li, %l, %s", first, second, third, floatValue);
      Serial.println("All together now:");
      Serial.println(newString);
  } else {
    Serial.println("NOT FOUND");
  }
    }  
  }
}

void parseWifiCreds(String body, char *parsedSSID, char *parsedPassword) {
  char bodyChar[100];
  body.toCharArray(bodyChar, sizeof(bodyChar));

  // pars key=value pairs
  char params[2][50];
  char delimiter[] = "&";
  char *token = strtok(bodyChar, delimiter);
  strncpy(params[0], token, sizeof(params[0]));
  char *token2 = strtok(NULL, delimiter);
  strncpy(params[1], token2, sizeof(params[1]));

  // parse param values from key=value pairs
  // char parsedParams[2][40];
  char valDelimiter[] = "=";
  char _ = strtok(params[0], valDelimiter);
  char *ssidToken = strtok(NULL, valDelimiter);
  strncpy(parsedSSID, ssidToken, sizeof(parsedSSID));
  char __ = strtok(params[1], valDelimiter);
  char *pwToken = strtok(NULL, valDelimiter);
  strncpy(parsedPassword, pwToken, sizeof(parsedPassword));
}

void setup() {
  Serial.begin(115200);
  //firstLesson();
  //secondLesson();
  //thirdLesson();
  //fourthLesson();
  //fifthLesson();
  // sixthLesson(); // <--- Use strtok to parse csv
  // seventhLesson();  // <- type casting and sprintf
  // eighthLesson();
  // ninethLesson();

  // Real world example parsing response body
  char parsedSSID[40];
  char parsedPassword[40];
  parseWifiCreds("ssid=YOURSSID123&password=YOURPASSWORD#%#", *parsedSSID, *parsedPassword);
  Serial.println(parsedSSID);
  Serial.println(parsedPassword);
}

void loop() {
  // put your main code here, to run repeatedly:

}
