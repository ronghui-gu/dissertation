Inductive pg_type := 
| PG_RESV | PG_KERN | PG_NORM.
Inductive page_info := 
| ATV (t: pg_type) (u: Z)
| ATUndef.
Record abs<@''@> :=
  { AT: ZMap.t page_info;
    ... }.
