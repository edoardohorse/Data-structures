# Data structures

# ListArray

Use an array as list

__Example of array of int (max length: 10)__

index | value                       
----- | ------                       
0|17                                 
1|70                                 
2|3                                  
3|30    

__Constructor with template__
```

    // first param is the type of single element
    // second one is the max length of the array (constant) 

    ListArray<int, 10>* ls = new ListArray<TypeElement, MaxLength>;     
    Ex: ListArray<int, 10>* ls = new ListArray<int, 10>;                 // object pointer
        auto* ls = new ListArray<int, 10>;                               // with auto
    or
    
    ListArray<TypeElement, MaxLength> ls;            
    Ex: ListArray<int, 10> ls;                                  // object
    
                                    
                                            
```
__Read and write__
```
    ls->get(position)                   // array[position] => element
    Ex: ls->get(2)                          // 3
    
    ls->set(position, elementToSet)     // array[position] = elementToSet;
    Ex: ls->set(1, 50)                      // array[1] = 50;
         ↓
      ╔═   ═╗       ╔═   ═╗
      ║  17 ║       ║  17 ║
      ║  70 ║   →   ║  50 ║
      ║   3 ║       ║   3 ║
      ║  30 ║       ║  30 ║
      ╚═   ═╝       ╚═   ═╝
    
```

__Insert and remove__
```
    ls->insert(position, elementToInsert)               
    Ex: ls->insert(1, 22)
            ↓
      ╔═   ═╗       ╔═   ═╗
      ║  17 ║       ║  17 ║
      ║  70 ║   →   ║  22 ║
      ║   3 ║       ║  70 ║
      ║  30 ║       ║   3 ║
      ╚═   ═╝       ║  30 ║
                    ╚═   ═╝
    
    ls->remove(position)
    Ex: ls->remove(1)
            ↓
      ╔═   ═╗       ╔═   ═╗
      ║  17 ║       ║  17 ║
      ║  70 ║   →   ║   3 ║
      ║   3 ║       ║  30 ║
      ║  30 ║       ╚═   ═╝
      ╚═   ═╝        
```

__Empty and last__
```
    ls->isEmpty()           // true if empty, otherwise false
    
    ls->isLast(position)    // check if a given position is the last one
```

__First, next and previous__
```
    ls->first()             // return the first index
    
    ls->next(position)      // position+1
    
    ls->previous(position)  // position-1
```

__Usage__
```
	auto* ls = new ListArray<int, 10>;
	ls->insert(0,17);
	ls->insert(1,20);
	ls->insert(2,3);
	ls->insert(3,30);

	ls->insert(1,70);
	ls->remove(2);

	PrintList::printListArray(*ls,4);       // need to import PrettyPrintList.h

	delete ls;
```