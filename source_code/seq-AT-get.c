uint at_get (uint i){ // <@$\kappa_{at\_get}$@>
  uint allocated; 
  allocated = AT[i].u; 
  if (allocated != 0)
    allocated = 1; 
  return allocated;
}
 // <@$\kappa_{at\_set}$@>
void at_set (uint i, uint b){
  AT[i].u = b;
}
