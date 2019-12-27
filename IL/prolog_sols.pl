%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

prod([X],X):-!.
prod([X|L],P):- prod(L,P1), P is P1*X.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

pescalar([],[],0).
pescalar([X|L1],[Y|L2],P):- pescalar(L1,L2,P1), P is P1+X*Y.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

interseccion([],_,[]).
interseccion([X|L1],L2,[X|L3]):- pert(X,L2),!, interseccion(L1,L2,L3).
interseccion([_|L1],L2,   L3 ):-               interseccion(L1,L2,L3).

union([],L,L).
union([X|L1],L2,   L3 ):- pert(X,L2),!, union(L1,L2,L3).
union([X|L1],L2,[X|L3]):-               union(L1,L2,L3).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

ultimo(L,X):- concat(_,[X],L).

inverso([],[]).
inverso(L,[X|L1]):- concat(L2,[X],L), inverso(L2,L1).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

fib(1,1):-!.
fib(2,1):-!.
fib(N,F):-
        %N>2,
        N1 is N-1, N2 is N-2, fib(N1,F1), fib(N2,F2), F is F1+F2.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

dados(0,0,[]).
dados(P,N,[X|L]):-
        %P>0,
        N>0,
        pert(X,[1,2,3,4,5,6]), Q is P-X, M is N-1, dados(Q,M,L).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

simplifica(E,E1):- unpaso(E,E2),!, simplifica(E2,E1).
simplifica(E,E).

unpaso(A+B,A+C):- unpaso(B,C),!.
unpaso(B+A,C+A):- unpaso(B,C),!.
unpaso(A*B,A*C):- unpaso(B,C),!.
unpaso(B*A,C*A):- unpaso(B,C),!.
unpaso(0*_,0):-!.
unpaso(_*0,0):-!.
unpaso(1*X,X):-!.
unpaso(X*1,X):-!.
unpaso(0+X,X):-!.
unpaso(X+0,X):-!.
unpaso(N1+N2,N3):- number(N1), number(N2), N3 is N1+N2,!.
unpaso(N1*N2,N3):- number(N1), number(N2), N3 is N1*N2,!.
unpaso(N1*X+N2*X,N3*X):- number(N1), number(N2), N3 is N1+N2,!.
unpaso(N1*X+X*N2,N3*X):- number(N1), number(N2), N3 is N1+N2,!.
unpaso(X*N1*X+N2*X,N3*X):- number(N1), number(N2), N3 is N1+N2,!.
unpaso(X*N1*X+X*N2,N3*X):- number(N1), number(N2), N3 is N1+N2,!.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

ord([],[]).
ord([X|L],L1):- ord(L,L2), insercion(X,L2,L1).
insercion(X,[],[X]).
insercion(X,[Y|L],[X,Y|L]):- X=<Y.
insercion(X,[Y|L],[Y|L1]):-  X> Y, insercion(X,L,L1).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

dicc(A,N):-  nmembers(A,N,S), escribir(S), fail.
nmembers(_,0,[]):-!.
nmembers(L,N,[X|S]):- pert(X,L), N1 is N-1, nmembers(L,N1,S).
escribir([]):-write(' '),nl,!.
escribir([X|L]):- write(X), escribir(L).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

suma([],[],[],C,C).
suma([X1|L1],[X2|L2],[X3|L3],Cin,Cout) :-
	X3 is (X1 + X2 + Cin) mod 10,
	C  is (X1 + X2 + Cin) //  10,
	suma(L1,L2,L3,C,Cout).


send_more_money1 :-

	L = [S, E, N, D, M, O, R, Y, _, _],
	permutacion(L, [0,1,2,3,4,5,6,7,8,9]),
	suma([D, N, E, S], [E, R, O, M], [Y, E, N, O], 0, M),

	write('S = '), write(S), nl,
	write('E = '), write(E), nl,
	write('N = '), write(N), nl,
	write('D = '), write(D), nl,
	write('M = '), write(M), nl,
	write('O = '), write(O), nl,
	write('R = '), write(R), nl,
	write('Y = '), write(Y), nl,
	write('  '), write([S,E,N,D]), nl,
	write('  '), write([M,O,R,E]), nl,
	write('-------------------'), nl,
	write([M,O,N,E,Y]), nl.


send_more_money2 :-

	L = [0,1,2,3,4,5,6,7,8,9],
	pertany_amb_resta(M,  [0,1], _),
	pertany_amb_resta(M,  L,  L0),
	pertany_amb_resta(O, L0, L1),
	pertany_amb_resta(R, L1, L2),
	pertany_amb_resta(Y, L2, L3),
	pertany_amb_resta(S, L3, L4),
	pertany_amb_resta(E, L4, L5),
	pertany_amb_resta(N, L5, L6),
	pertany_amb_resta(D, L6, _),
	suma([D, N, E, S], [E, R, O, M], [Y, E, N, O], 0, M),

	write('S = '), write(S), nl,
	write('E = '), write(E), nl,
	write('N = '), write(N), nl,
	write('D = '), write(D), nl,
	write('M = '), write(M), nl,
	write('O = '), write(O), nl,
	write('R = '), write(R), nl,
	write('Y = '), write(Y), nl,
	write('  '), write([S,E,N,D]), nl,
	write('  '), write([M,O,R,E]), nl,
	write('-------------------'), nl,
	write([M,O,N,E,Y]), nl.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
