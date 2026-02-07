//Using  4 states for none,led1,led2,led3 and all
enum State {St0, St1, St2, St3, St4};
State currentState = St0;

void setup() {
  DDRB = 0xF0;
  DDRB |= (1 << DDB0) | (1 << DDB1) | (1 << DDB2);
  DDRB = 0x7;

 
  DDRD &= ~(1 << DDD2);
}

void loop() {
  
  if (PIND & (1 << PIND2)) {
   
    switch (currentState) {
      case St0: currentState = St1; break;
      case St1: currentState = St2; break;
      case St2: currentState = St3; break;
      case St3: currentState = St4; break;
      default: currentState = St0; break;
    }

    
    while (PIND & (1 << PIND2));
  }

  switch (currentState) {
    case St0:  
      PORTB &= ~((1 << PORTB0) | (1 << PORTB1) | (1 << PORTB2));
      break;

    case St1:  
      PORTB |= (1 << PORTB0);
      PORTB &= ~((1 << PORTB1) | (1 << PORTB2));
      break;

    case St2: 
      PORTB |= (1 << PORTB1);
      PORTB &= ~((1 << PORTB0) | (1 << PORTB2));
      break;

    case St3: 
      PORTB |= (1 << PORTB2);
      PORTB &= ~((1 << PORTB0) | (1 << PORTB1));
      break;

    case St4: 
      PORTB |= (1 << PORTB0) | (1 << PORTB1) | (1 << PORTB2);
      break;
  }
}