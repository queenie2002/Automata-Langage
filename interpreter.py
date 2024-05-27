#!/usr/bin/env python3

asm = open("output_files/instructions.txt", "r").readlines()
asm = [l.strip().split(" ") for l in asm]
asm = [[int(a, 16) for a in l] for l in asm]

for instruction in asm: 
    print(instruction)

ip = 0 

# Memory of size 1024
mem = [0] * 1024    

NOP = 0
ADD = 1
MUL = 2
SUB = 3
DIV = 4
COP = 5
AFC = 6
JMP = 7
JMF = 8
INF = 9
SUP = 10
EQU = 11
PRI = 12
ERR = 255 #problem couldn't recognize instruction



while (ip < len(asm)) :
    if asm[ip][0] == ADD:
        mem[asm[ip][1]] = mem[asm[ip][2]] + mem[asm[ip][3]]
        
    elif asm[ip][0] == MUL: 
        mem[asm[ip][1]] = mem[asm[ip][2]] * mem[asm[ip][3]]
    
    elif asm[ip][0] == SUB: 
        mem[asm[ip][1]] = mem[asm[ip][2]] - mem[asm[ip][3]]
    
    elif asm[ip][0] == DIV: 
        mem[asm[ip][1]] = mem[asm[ip][2]] / mem[asm[ip][3]]
    
    elif asm[ip][0] == COP: 
        mem[asm[ip][1]] = mem[asm[ip][2]]
    
    elif asm[ip][0] == AFC: 
        mem[asm[ip][1]] = asm[ip][2]
    
    elif asm[ip][0] == JMP: 
        ip = asm[ip][2] - 1  #we decrease so that after ip+1, we get to the right instruction
        
    elif asm[ip][0] == JMF: 
        if mem[asm[ip][1]] == 0 : #false, we jump to else
            ip = mem[asm[ip][2]] - 1 
        #if it's 1: it's true and we continue normally, we're not dealing with error here            
        
    elif asm[ip][0] == INF: 
        if mem[asm[ip][2]] < mem[asm[ip][3]] : #if it's true
            mem[asm[ip][1]] = 1 
        else:
            mem[asm[ip][1]] = 0
    
    elif asm[ip][0] == SUP: 
        if mem[asm[ip][2]] > mem[asm[ip][3]] : #if it's true
            mem[asm[ip][1]] = 1 
        else:
            mem[asm[ip][1]] = 0
        
    elif asm[ip][0] == EQU: 
        if mem[asm[ip][2]] == mem[asm[ip][3]] : #if it's true
            mem[asm[ip][1]] = 1 
        else:
            mem[asm[ip][1]] = 0
           
    elif asm[ip][0] == PRI: 
        print(mem[asm[ip][1]])

    elif asm[ip][0] == ERR: 
        print("error couldn't recognize instruction")
    
    ip+=1
