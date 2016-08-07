typedef enum { 
  PG_RESV, PG_KERN, PG_NOTM
} pg_type;
struct page_info { 
  pg_type t;
  uint u;
};
struct page_info AT[1<<20];// <@$\nu_\textsf{AT}$@>
