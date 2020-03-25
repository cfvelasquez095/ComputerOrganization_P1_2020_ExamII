# Ejercicio 1
Crear un sistema de memoria cache directamente mapeada en Digital
para un sistema de direccionamiento de 32 bits. Para el almacenamiento
deberá utilizar la memoria ROM de Digital.

La caché utilizará 1 palabra por bloque y deberá contener 1024 lineas.

El procedimiento para probar el circuito es el siguiente:
1. Crear el circuito en Digital. Asegurarse de colocar el label CacheMem
   a la memoria ROM. Finalmente guardar el circuito con el nombre Ejer1.dig
2. Exportar el archivo de verilog con el nombre Ejer1.v 
   y colocarlo en el subfolder verilog/ del ejercicio 1.
3. Crear el folder build/
4. Ingresar al folder build y ejecutar el comando cmake ../test-cases
5. Ejecutar el comando make para compilar los test cases
6. Si el comando anterior tuvo exito, correr el ejecutable ./test_Ejer1

# Ejercicio 2
Convertir el programa en C find_minimum.c a ensamblador x86.
