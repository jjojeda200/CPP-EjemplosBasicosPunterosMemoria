# Punteros

Los punteros son variables que guardan una dirección de memoria. Como cualquier variable su valor puede ser constante o no. Los punteros son especiales por no tener sólo un tipo de qué son – una dirección de memoria – sino por tener también otro tipo asociado del valor a que apuntan. Y este valor puede ser constante o variable de forma independiente. Por este motivo puede haber dos const en la definición de un puntero.

      int        variable = 1;
const int        constante = 2;
const int *      puntero_a_constante = &constante;
      int *const puntero_constante_a_variable = &variable;
const int *const puntero_constante_a_constante = &constante;

    El puntero_a_constante puede apuntar a varios objetos, pero no puede modificarlos. Cadenas de caracteres se definen típicamente así: como const char*.

    Un puntero_constante_a_variable puede modificar el objeto a que apunta, pero no puede apuntar a otra cosa.
    
    Finalmente, un puntero_constante_a_constante ni puede modificar el objeto a que apunta ni apuntar a otro objeto. Por este punto de vista una cadena de texto hardcoded tiene realmente el tipo const char *const. Sin embargo, se usa poco.

# Referencias

Para las referencias valen básicamente las mismas reglas que para punteros. No obstante hay una importante diferencia: referencias no pueden referirse a otra instancia. Al contrario de punteros las referencias no pueden existir por si mismas sino deben inicializarse a la hora de ser declarada.

      int        variable = 1;
const int        constante = 2;
const int &      referencia_a_constante = constante;

// &const es permitido pero innecesario. Por eso nunca se usa.
      int &const referencia_constante_a_variable = variable;
const int &const referencia_constante_a_constante = constante;

Como las referencias apuntan al mismo objeto durante toda su vida, & y &const es lo mismo, y por eso nunca se escribe &const.

Es fácil hacer un cast para convertir un puntero de un objeto a otro objeto con un tipo diferente. Las referencias, en cambio, tienen el mismo tipo que el objeto a que se refieren y aportan más seguridad contra un cast implícito.  Por eso es preferible usar referencias en lugar de punteros siempre cuando sea posible.

Muy especialmente conviene usar referencias a constantes en lugar de constantes como parámetros de funciones. Se usan igual pero sólo requieren copiar un puntero en lugar de un objeto entero. Es decir, no se llamará un constructor para una referencia.

# Clases constantes

Igual como se puede convertir un tipo simple como int a constante, se puede declarar const a una estructura compleja. La construcción const MiClase convierte todos los miembros de esta instancia en constantes. Sólo se les pueden asignar un valor en el constructor y después ya no. Se puede forzar una excepción para un campo en la clase declarándolo mutable, pero en general hay poca razón de hacerlo.

También es posible declarar campos individuales constantes dentro de una clase. Por ejemplo, puedo crear una clase que guarde una posición como una posición inicial constante y un desplazamiento variable.

class MiSitio
{
    double desplazamiento;          // una variable
    const double posicion_inicial;  // una constante
};

El valor de posicion_inicial sería asignado en el constructor de la clase y se quedaría inmodificable durante la vida de la instancia. No obstante, cada instancia puede tener otro valor para posicion_inicial. Por lo tanto un miembro constante no es los mismo que una constante global y común a todas las instancias.

Lo que queda por hacer constante son los métodos de una clase. Métodos constantes «prometen» de no modificar ningún dato dentro de la clase. (Más correctamente ninguno que no sea mutable.) Son los únicos métodos que puedo llamar para una instancia constante.

class MiCosa
{
public:
    int mi_variable;

    void mi_metodo_constante() const
    {
        mi_variable = 0;  // Error de compilación.
        // No debo modificar campos en un método constante.
    };

    void mi_metodo_variable()
    {
        mi_variable = 0;  // Ok
    };
};

const MiCosa cosa;
cosa.mi_metodo_constante();  // Ok
cosa.mi_metodo_variable();   // Error de compilación.
// No puedo llamar a un método NO constante para un objeto constante.

Para complicar la cosa aún más, se pueden definir dos métodos iguales en que una es constante y la otra no. Es algo que usa mucho para los métodos que devuelven iteradores de inicio y final en los contenedores de la STL.

iterator begin(void);
const_iterator begin(void) const;

El método constante devuelve un iterador (puntero) a un objeto constante, mientras la versión variable devuelve un iterador a un objeto variable.