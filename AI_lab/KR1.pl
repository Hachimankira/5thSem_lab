contains_sugar(kheer).
contains_sugar(jeripuri).
contains_salt(namkeen).
contains_salt(samosa).

sweetdish(Dish) :-
    contains_sugar(Dish).
saltydish(Dish) :-
    contains_salt(Dish).