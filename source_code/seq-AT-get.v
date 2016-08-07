Function <@$\spec_\textsf{at\_get}$@> a i := 
  match (a.AT i) with
    | ATV _ 0 => Some 0
    | ATV _ _ => Some 1
    | _ => None 
  end.
Function <@$\spec_\textsf{at\_set}$@> a i b := 
  match (a.AT i) with
    | ATV t _ => Some(a{AT,i:ATV t b})
    | _ => None
  end.