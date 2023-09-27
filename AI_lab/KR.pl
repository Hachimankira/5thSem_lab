eats(tiger, meat).
eats(cow, vegetable).
eats(human, meat).
eats(human, vegetable).

carnivore(X) :- eats(X, meat).
omnivore(X) :- eats(X, vegetable), eats(X, meat).
herbivore(X) :- eats(X, vegetable).
