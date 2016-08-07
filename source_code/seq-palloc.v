Inductive <@$\sigma_\textsf{palloc}'$@> := // low-level spec
| <@$\forall$@> m a a<@'@> nps n,
    <@$\spec_\textsf{palloc}$@> a nps = (a<@'@>, n) ->
    0 <= nps < 1048576 ->
    <@$\sigma_\textsf{palloc}'$@> (nps::nil) m a n m a<@'@>.
Definition <@$\sigma_\textsf{palloc}$@> := <@$\sigma_\textsf{palloc}'$@>. // low-level spec
