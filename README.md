# Data structures

# ListArray

Use an array like list



_Constructor with template_
```

    // first param is the type of single element
    // second one is the max length of the array (constant) 

    ListArrya* ls = new ListArray<int, 10>;     // object pointer
    // code
    delete ls                                   // destroy
    
    or
    
    ListArrya<int, 10> ls;                      // object
    
       index | value                       
       ----- | ------                       ╔═   ═╗
       0|17                                 ║  17 ║
       1|70                                 ║  70 ║
       2|3                                  ║   3 ║
       3|30                                 ║  30 ║
                                            ╚═   ═╝
```
_Read and write_
```
    ls->get(position)                   // array[position] => element
    ls->get(0)                          // 
    
    ls->set(position, elementToSet)     // array[position] = elementToSet;
```

_Insert and remove_
```
    ls->insert(position)
    
```