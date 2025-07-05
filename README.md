# Proyecto 2: Terminal Unix

[cite_start]Este proyecto consiste en el desarrollo de una aplicación en **C++** que simula una terminal Unix básica. [cite: 5, 6] [cite_start]La aplicación gestionará un sistema de archivos dinámico y jerárquico [cite: 7, 12][cite_start], y permitirá la interacción del usuario a través de un conjunto de comandos Unix fundamentales. [cite: 8]

## Descripción del Proyecto

El objetivo principal es crear una terminal funcional que replique la experiencia de un entorno Unix básico. [cite_start]La aplicación debe ser desarrollada en C++ [cite: 42][cite_start], utilizando estructuras de datos dinámicas propias (no librerías predefinidas del lenguaje) [cite: 45, 46][cite_start], y será compilada con Visual Studio Code. [cite: 43]

## Requisitos y Funcionalidades Clave

* [cite_start]**Carga y Persistencia del Sistema de Archivos**: Al inicio, la aplicación leerá un archivo de texto plano para cargar la estructura inicial de carpetas y archivos en una estructura de datos jerárquica. [cite: 11, 12] [cite_start]Al finalizar (comando `exit`), los cambios realizados en la estructura se guardarán de nuevo en este archivo para asegurar la persistencia. [cite: 39, 40]

* [cite_start]**Comandos Unix Implementados**: Se deben implementar los siguientes comandos básicos, soportando tanto rutas absolutas como relativas[cite: 15, 27]:
    * [cite_start]`cd <ruta>`: Cambiar el directorio actual. [cite: 16]
    * [cite_start]`ls`: Listar el contenido del directorio actual (nombres de carpetas y archivos). [cite: 19]
    * [cite_start]`mkdir <nombre_carpeta>`: Crear una nueva carpeta en el directorio actual. [cite: 20]
    * [cite_start]`rm <nombre_archivo_o_carpeta>`: Eliminar un archivo o una carpeta (si es carpeta, se elimina recursivamente su contenido). [cite: 21]
    * [cite_start]`touch <nombre_archivo>`: Crear un nuevo archivo de texto plano en el directorio actual. [cite: 22, 23]
    * [cite_start]`exit`: Finalizar la ejecución de la terminal y guardar los cambios. [cite: 24, 39]

* **Edición y Manipulación de Contenido**:
    * [cite_start]Se permitirá el cambio de nombre a carpetas y archivos de texto plano. [cite: 25]
    * [cite_start]Se debe implementar un pequeño editor de texto para mostrar y editar el contenido de los archivos de texto directamente en la consola. [cite: 26]

* [cite_start]**Validación y Manejo de Errores**: La implementación de los comandos debe incluir validaciones para las entradas del usuario y manejar posibles errores (ej. ruta no encontrada, archivo/carpeta ya existente). [cite: 33]

## Consideraciones Técnicas

* [cite_start]Se utilizará una estructura de datos jerárquica dinámica (como árboles o listas enlazadas anidadas) para representar el sistema de archivos, garantizando una navegación y manipulación eficiente. [cite: 12, 32, 45]
* [cite_start]El proyecto debe ser desarrollado para su uso por consola. [cite: 44]
* [cite_start]Es obligatorio el uso de Git para el control de versiones y el alojamiento del código en un repositorio privado de GitHub. [cite: 47] [cite_start]Se valorarán las buenas prácticas en commits y manejo de ramas, y solo se revisará el código de la rama principal subido antes del día de la corrección. [cite: 48, 49, 50, 51]
* [cite_start]Se tomarán en cuenta las buenas prácticas de codificación, incluyendo documentación, estándares de nombres para variables y funciones, y el buen uso de funciones y librerías. [cite: 52]

---

**Nota:** Este `README` proporciona una visión general y los puntos clave del proyecto. Para detalles específicos sobre la implementación y la estructura de datos, consultar la documentación interna del código.
