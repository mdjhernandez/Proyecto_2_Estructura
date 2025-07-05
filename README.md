# Proyecto 2: Terminal Unix

Este proyecto consiste en el desarrollo de una aplicación en **C++** que simula una terminal Unix básica. La aplicación gestionará un sistema de archivos dinámico y jerárquico, y permitirá la interacción del usuario a través de un conjunto de comandos Unix fundamentales.

## Descripción del Proyecto

El objetivo principal es crear una terminal funcional que replique la experiencia de un entorno Unix básico. La aplicación debe ser desarrollada en C++, utilizando estructuras de datos dinámicas propias (no librerías predefinidas del lenguaje), y será compilada con Visual Studio Code.

## Requisitos y Funcionalidades Clave

* **Carga y Persistencia del Sistema de Archivos**: Al inicio, la aplicación leerá un archivo de texto plano para cargar la estructura inicial de carpetas y archivos en una estructura de datos jerárquica. Al finalizar (comando `exit`), los cambios realizados en la estructura se guardarán de nuevo en este archivo para asegurar la persistencia.

* **Comandos Unix Implementados**: Se deben implementar los siguientes comandos básicos, soportando tanto rutas absolutas como relativas:
    * `cd <ruta>`: Cambiar el directorio actual.
    * `ls`: Listar el contenido del directorio actual (nombres de carpetas y archivos).
    * `mkdir <nombre_carpeta>`: Crear una nueva carpeta en el directorio actual.
    * `rm <nombre_archivo_o_carpeta>`: Eliminar un archivo o una carpeta (si es carpeta, se elimina recursivamente su contenido). [cite: 21]
    * `touch <nombre_archivo>`: Crear un nuevo archivo de texto plano en el directorio actual.
    * `exit`: Finalizar la ejecución de la terminal y guardar los cambios.

* **Edición y Manipulación de Contenido**:
    * Se permitirá el cambio de nombre a carpetas y archivos de texto plano.
    * Se debe implementar un pequeño editor de texto para mostrar y editar el contenido de los archivos de texto directamente en la consola.

* **Validación y Manejo de Errores**: La implementación de los comandos debe incluir validaciones para las entradas del usuario y manejar posibles errores (ej. ruta no encontrada, archivo/carpeta ya existente).

## Consideraciones Técnicas

* Se utilizará una estructura de datos jerárquica dinámica (como árboles o listas enlazadas anidadas) para representar el sistema de archivos, garantizando una navegación y manipulación eficiente.
* El proyecto debe ser desarrollado para su uso por consola.
* Es obligatorio el uso de Git para el control de versiones y el alojamiento del código en un repositorio privado de GitHub. Se valorarán las buenas prácticas en commits y manejo de ramas, y solo se revisará el código de la rama principal subido antes del día de la corrección.
* Se tomarán en cuenta las buenas prácticas de codificación, incluyendo documentación, estándares de nombres para variables y funciones, y el buen uso de funciones y librerías.

---

**Nota:** Este `README` proporciona una visión general y los puntos clave del proyecto. Para detalles específicos sobre la implementación y la estructura de datos, consultar la documentación interna del código.
