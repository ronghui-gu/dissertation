struct ticket_lock{
  volatile uint ticket;
  volatile uint now;
};

// <@$L_1$@> layer interface
extern uint FAI_ticket();
extern uint get_now();
extern void hold_lock();
extern void inc_now();
extern void f();
extern void g();

// <@$M_1$@> module
void acq () {
  uint myt = FAI_ticket();
  while(get_now()!=myt){};
  hold();
}

void rel () { inc_now(); }
// <@$L_2$@> layer interface
extern void acq();
extern void rel();
extern void f();
extern void g();

// <@$M_2$@> module
void foo () {
  acq();
  f(); g();
  rel();
}

// <@$L_3$@> layer interface
extern void foo();

// Client program <@$P$@>
// Thread running on CPU 1
void T1 () { foo(); }
// Thread running on CPU 2
void T2 () { foo(); }

