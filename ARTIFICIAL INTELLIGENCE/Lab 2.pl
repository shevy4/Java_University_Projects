phone(id(z101),name('Samsung Galaxy'),country('Japan'),new_version('S8')).
phone(id(z102),name('LG'),country('Japan'), new_version('G7 ThinQ')).
phone(id(x103),name('Sony'),country('China'), new_version('Xperia XZ2')).
phone(id(x104),name('Samsung'),country('China'), new_version('Galaxy Note8')).
phone(id(x105),name('Sony'),country('Japan'), new_version('Xperia X3')).
phone(id(z106),name('LG'),country('Japan'), new_version('G8')).

% os(OSType,TypeList) - The list of phones by operating system.

os(android,[z101,x103,z106]).
os(iphone,[z102,x104,x105]).

%oscost(OSType,CostList) - The list of phones by unitcost.

ostypecost(android,[1000,2700,2100]).
ostypecost(iphone,[1500,1200,1700]).

% version(phone_id, otherversion) - A list of other versions for the phones.

version(id(z101),[xperia1,v8]).
version(id(z102),[v8,xperia3]).
version(id(x103),[xperia1,xperia2,xperia3]).
version(id(x104),[xperia1,note7]).
version(id(x105),[note7,v8]).
version(id(z106),[note7,xperia2]).

%Useful predicates%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%similar to member – checks if an element is in a list
in_list(X,[X|_]).
in_list(X,[_|T]) :- in_list(X,T).

%Counts the elements is in a list
countList([], 0).
countList([_|T], N) :- countList(T, NT), N is 1+NT.

%Returns the total of the elements is in a list
sumList([], 0).
sumList([H|T],S) :- sumList(T, NS), S is H + NS.



%Returns the maximum element is in a list
maxList([E],E).
maxList([H|T],Y):- maxList(T,Y), H < Y,!.
maxList([H|_],H).

%works like the append function
concatlist([],List2,List2).
concatlist([Item|Tail],List2,[Item|Newlist]) :-
	concatlist(Tail,List2,Newlist).


%Question #1


list_phones:- write('ID'), write('       '), write('Name'), tab(12), write('Country'),
	      tab(15),write('Version'),tab(10),write('OS'),tab(10),
	      write('Max Cost'),nl, prt_phone, fail.

prt_phone:- os(android,Android),phone(id(Id),name(Name),
	      country(Country),new_version(Version)),member(Id,Android),
	      write(Id),tab(5), write(Name),tab(15),
	      write(Country),tab(10), write(Version),tab(10),write('Android'),
	      ostypecost(android,L1),ostypecost(iphone,L2),
	      maxList(L1,MaxList),tab(10),write(MaxList),nl,

	      os(iphone,Iphone),phone(id(ID),name(Iosname),country(Ioscountry),
	      new_version(Iosversion)), member(ID,Iphone),
	      write(ID),tab(5), write(Iosname),tab(15),
	      write(Ioscountry),tab(10), write(Iosversion),tab(10),write('IOS'),
	      tab(10),maxList(L2,MaxList2),write(MaxList2),nl.


% Question #B

phone_vg:- ostypecost(android, L1), ostypecost(iphone,L2),
	append(L1,L2,Newlist), sumList(Newlist, Sum),nl,
	countList(Newlist, Count), Avg is Sum/Count, nl,
	write('Average = '), write(Avg),nl,
	maxList(L1,MaxList), write(MaxList).

% Question #C

%Returns the min element is in a list
minList([E],E).
minList([H|T],Y):- minList(T,Y), H > Y,!.
minList([H|_],H).

phone_max(OSType,Maxcost):-  ostypecost(OSType,L1),maxList(L1,MaxList),
			     minList(L1, MinList),write('Maxcost = '),write(MaxList),nl,
			     write('Mincost = '),write(MinList),nl,
			     Maxcost is MaxList.

%Question D


phoneversion(Version):- prt_phoneversion(Version),
	                version(Alt,L1),version(Alt,_) ,member(Version,L1),
			nl,write(Alt),fail.

prt_phoneversion(Version):- write('The Following Phones Are Associated With :'),
	                    write(Version).

% Question #E

getsecond(List) :-nth0(1,List,X),write('Second Element = '),write(X).

% Question # 2

ceo:-
      Conduct_meetings_well = [dave, thomas],
      Management_degree = [dave, thomas],in_list(X,Conduct_meetings_well),
      in_list(X, Management_degree),
      write(X), write(' is Suitable For CEO'),nl, advisor.

advisor:-
	  Finace_degree = [sue, fred],
	  Management_degree = [dave, thomas, sue],in_list(X,Finance_degree),
	  in_list(X, Management_degree),
	  write(X), write(' is Suitable For Advisor'),nl,strategist.

strategist:-
	    Analytical = [fred, jack],
	    Finace_degree = [sue, fred],in_list(X,Analytical), in_list(X, Finace_degree),
	    write(X), write(' is Suitable For Strategist').
