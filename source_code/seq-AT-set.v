Inductive <@$\sigma_\textsf{at\_set}'$@> := // low-level spec
| <@$\forall$@> m m<@'@> a v n,
    m.store AT (n * 8 + 4) v m = m<@'@> ->
    0 <= n < 1048576 ->
    <@$\sigma_\textsf{at\_set}'$@> (n::v::nil) m a Vundef m<@'@> a.
Inductive <@$\sigma_\textsf{at\_set}$@> := // high-level spec
| <@$\forall$@> m a a<@'@> v n,
    <@$\spec_\textsf{at\_set}$@> a n v = Some a<@'@> ->
    0 <= n < 1048576 ->
    <@$\sigma_\textsf{at\_set}$@> (n::v::nil) m a Vundef m a<@'@>.
