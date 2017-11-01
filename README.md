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

_Constructor with template_
```

    // first param is the type of single element
    // second one is the max length of the array (constant) 

    ListArrya* ls = new ListArray<int, 10>;     // object pointer
    
    or
    
    ListArrya<int, 10> ls;                      // object
    
                                    
                                            
```
_Read and write_
```
    ls->get(position)                   // array[position] => element
    ls->get(2)                          // 3
    
    ls->set(position, elementToSet)     // array[position] = elementToSet;
    ls->set(1, 50)                      // array[1] = 50;
         ↓
      ╔═   ═╗       ╔═   ═╗
      ║  17 ║       ║  17 ║
      ║  70 ║   →   ║  50 ║
      ║   3 ║       ║   3 ║
      ║  30 ║       ║  30 ║
      ╚═   ═╝       ╚═   ═╝
    
```

_Insert and remove_
```
    ls->insert(position, elementToInsert)               
    ls->insert(1, 22)
            ↓
      ╔═   ═╗       ╔═   ═╗
      ║  17 ║       ║  17 ║
      ║  70 ║   →   ║  22 ║
      ║   3 ║       ║  70 ║
      ║  30 ║       ║   3 ║
      ╚═   ═╝       ║  30 ║
                    ╚═   ═╝
    
    ls->remove(position)
    ls->remove(1)
            ↓
      ╔═   ═╗       ╔═   ═╗
      ║  17 ║       ║  17 ║
      ║  70 ║   →   ║   3 ║
      ║   3 ║       ║  30 ║
      ║  30 ║       ╚═   ═╝
      ╚═   ═╝        
```

_Empty and last_
```
    ls->isEmpty()           // true if empty, otherwise false
    
    ls->isLast(position)    // check if a given position is the last one
```

_First, next and previous_
```
    ls->first()             // return the first index
    
    ls->next(position)      // position+1
    
    ls->previous(position)  // position-1
```
