asm = open("output_files/instructions.txt", "r").readlines()
asm = [l.strip().split(" ") for l in asm]
asm = [[int(a, 16) for a in l] for l in asm]

# Instruction Pointer
ip = 0 

# Stack Pointer
sp = 0

# Memory of size 1024
mem = [0] * 1024
mem[0] = -1 

NOP = 0   #skips
ADD = 1   #adds
MUL = 2   #multiplies
SUB = 3   #subtracts
DIV = 4   #divides
COP = 5   #copies
AFC = 6   #affects
JMP = 7   #jumps
JMF = 8   #jumps if
INF = 9   #inferior to
SUP = 10  #superior to
EQU = 11  #equal to
PRI = 12  #print
RET = 13  #return
NEQ = 14  #different
LEQ = 15  #less or equal to
GEQ = 16  #greater or equal to
AND = 17  #and
ORR = 18  #or
NOT = 19  #not
CALL = 20 #call
PUSH = 21 #push
POP = 22  #pop
ERR = 255 #problem couldn't recognize instruction

def get_register(ip,j):
    return asm[ip][j] + sp

done = 0



while (ip < len(asm) and not done) :
    #print("\n\ninstruction: " + str(ip))
    #print(str(asm[ip][0]) + " " + str(asm[ip][1]) + " " + str(asm[ip][2]) + " " + str(asm[ip][3]) + " " )
    #print("stack pointer: " + str(sp))
    
    #print("done: " + str(done))

    
    if ip == -1:
        done = 1 #stop when we reach end of main
        
    elif asm[ip][0] == NOP:
        pass
    
    elif asm[ip][0] == ADD:
        mem[get_register(ip,1)] = mem[get_register(ip,2)] + mem[get_register(ip,3)]
        
    elif asm[ip][0] == MUL: 
        mem[get_register(ip,1)] = mem[get_register(ip,2)] * mem[get_register(ip,3)]
    
    elif asm[ip][0] == SUB: 
        mem[get_register(ip,1)] = mem[get_register(ip,2)] - mem[get_register(ip,3)]
    
    elif asm[ip][0] == DIV: 
        mem[get_register(ip,1)] = mem[get_register(ip,2)] / mem[get_register(ip,3)]
    
    elif asm[ip][0] == COP: 
        mem[get_register(ip,1)] = mem[get_register(ip,2)]
    
    elif asm[ip][0] == AFC: 
        mem[get_register(ip,1)] = asm[ip][2]
    
    elif asm[ip][0] == JMP: 
        ip = asm[ip][1] - 1  #we decrease so that after ip+1, we get to the right instruction
        
    elif asm[ip][0] == JMF:  #works so that if 1 true, else is false and skips, not only 0 is false
        if mem[get_register(ip,1)] == 1 : #true, we continue normally
            pass
        else : #false, we jump to else
            ip = asm[ip][2] - 1      
        
    elif asm[ip][0] == INF: 
        if mem[get_register(ip,2)] < mem[get_register(ip,3)] : #if it's true
            mem[get_register(ip,1)] = 1 
        else:
            mem[get_register(ip,1)] = 0
            
    
    elif asm[ip][0] == SUP: 
        if mem[get_register(ip,2)] > mem[get_register(ip,3)] : #if it's true
            mem[get_register(ip,1)] = 1 
        else:
            mem[get_register(ip,1)] = 0
        
    elif asm[ip][0] == EQU: 
        if mem[get_register(ip,2)] == mem[get_register(ip,3)] : #if it's true
            mem[get_register(ip,1)] = 1 
        else:
            mem[get_register(ip,1)] = 0
           
    elif asm[ip][0] == PRI: 
        print(mem[get_register(ip,1)])

    elif asm[ip][0] == RET: 
        ip = mem[sp] - 1
        
    elif asm[ip][0] == NEQ: 
        if mem[get_register(ip,2)] != mem[get_register(ip,3)] : #if it's true
            mem[get_register(ip,1)] = 1 
        else:
            mem[get_register(ip,1)] = 0
    
    elif asm[ip][0] == LEQ: 
        if mem[get_register(ip,2)] <= mem[get_register(ip,3)] : #if it's true
            mem[get_register(ip,1)] = 1 
        else:
            mem[get_register(ip,1)] = 0
    
    elif asm[ip][0] == GEQ: 
        if mem[get_register(ip,2)] >= mem[get_register(ip,3)] : #if it's true
            mem[get_register(ip,1)] = 1 
        else:
            mem[get_register(ip,1)] = 0
            
    elif asm[ip][0] == AND: 
        if ((mem[get_register(ip,2)]==1) and (mem[get_register(ip,3)]==1)) : #if both are true, true
            mem[get_register(ip,1)] = 1 
        else:
            mem[get_register(ip,1)] = 0
            
    elif asm[ip][0] == ORR: 
        if mem[get_register(ip,2)] or mem[get_register(ip,3)] : #if one of the two is true, true
            mem[get_register(ip,1)] = 1 
        else:
            mem[get_register(ip,1)] = 0
            
    elif asm[ip][0] == NOT: 
        if mem[get_register(ip,2)] != 1 : #if it's not true, true
            mem[get_register(ip,1)] = 1 
        else:
            mem[get_register(ip,1)] = 0
    
    elif asm[ip][0] == CALL: 
        mem[sp] = ip+1 #we memorize the next instruction in caller fct to come back to

        ip = asm[ip][1] - 1 #we jump to function
        
    elif asm[ip][0] == PUSH: 
        sp = asm[ip][1] + sp #memorizes where the frame for callee fct starts

    elif asm[ip][0] == POP: 
        sp -= asm[ip][1]
        
    
    else : 
        print("error couldn't recognize instruction " + str(asm[ip][0]))
    
    #print(mem[0:20],"\n")
    ip+=1
