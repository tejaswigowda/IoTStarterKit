enum STATE    {CONNECTAP, CONNECTHOST, LISTEN, SEND, NUMSTATES} state;              //State of program. DO NOT insert new elements at the end.
enum RetCodes {SUCCESS, FAIL, REPEAT, NUMRETCODES} rc;                              //Possible return codes for all of the state functions. DO NOT insert new elements at end.

struct transition{                                                                  //Struct containscurrent state, return code and corresponding next state
  STATE     curState;
  RetCodes  curRC;
  STATE     nextState;
};

const uint8_t tablesize = 10;                                                       //Table containing transitions. Each row contains a "current state" and "return code" and the 3rd element in each row is the appropriate next state
transition table[10] = {
  {CONNECTAP,   SUCCESS,  CONNECTHOST},
  {CONNECTAP,   FAIL,     CONNECTAP},
  {CONNECTHOST, SUCCESS,  LISTEN},
  {CONNECTHOST, FAIL,     CONNECTHOST},
  {LISTEN,      SUCCESS,  SEND},
  {LISTEN,      FAIL,     LISTEN},
  {LISTEN,      REPEAT,   LISTEN},
  {SEND,        SUCCESS,  LISTEN},
  {SEND,        FAIL,     SEND},
  {SEND,        REPEAT,   SEND}
};

STATE getNextState(STATE stateprev, RetCodes rcprev){                               //Gets the next state of the program from the current state and response code
  for(int i = 0; i < tablesize; i++){
    if(table[i].curState == stateprev && table[i].curRC == rcprev){
      return table[i].nextState;
    }//if
  }//for

  return CONNECTAP;
}//nextState


RetCodes do_connectAP(int* data){                                                   //connect to router
  Serial.println("do_connectAP");
  return SUCCESS;                                                                   
}//do_connectAP

RetCodes do_connecthost(int* data){                                                 //connect to server
  Serial.println("do_connectHOST");
  return SUCCESS;                                                                   
}//do_connecthost

RetCodes do_listen(int* data){                                                      //wait for messages from server
  Serial.println("do_listen");
  return SUCCESS;                                                                   
}//do_listen

RetCodes do_send(int* data){                                                        //send message to server
  Serial.println("do_send");
  return SUCCESS;                                                                   
}//do_send

RetCodes (*funcptrs[])(int*) = {do_connectAP, do_connecthost, do_listen, do_send};  //Array of function pointers. Each elements corresponds to a specific state. i.e. rc = funcptrs[CONNECTAP](0);


void setup() {                                                                      //setup only invoked once in program lifetime
  Serial.begin(115200);
  state = CONNECTAP;
}//setup


unsigned long tick;
unsigned long tock;                                                                 //get duration of state each pass through loop
void loop() {                                                                       //put your main code here, to run repeatedly:
  tick = millis();                                                                  //start time

  rc = funcptrs[state](0);                                                          //run state function and get return code
  state = getNextState(state, rc);                                                  //loop up next state
  
  tock = millis();                                                                  //stop time

  Serial.println( (tock - tick) );                                                  //print time interval

  delay(500);
}//loop                                                                             //repeat now that state is updated...
