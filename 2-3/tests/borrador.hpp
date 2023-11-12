#include "tt.hpp"

namespace trees {

void tt::insert_rec(int val, ttNode* node) {
    if (node->getSize() == 0) {
        // Nodo vacío, insertamos directamente
        node->setData(val);
        node->setSize(1);
    } else {
        if (node->getData2() == -1) {
            // Nodo de 2 claves
            switch (compareKeys(val, node->getData())) {
                case 0:
                    // Clave de y coincide con clave en p
                    // ERROR, ETIQUETA EXISTENTE;
                    // Aquí debes manejar el error según tus necesidades
                    break;
                case 1:
                    // p apunta a un nodo hoja
                    if (val < node->getData()) {
                        node->setData2(node->getData());
                        node->setData(val);
                    } else {
                        node->setData2(val);
                    }
                    node->setSize(2);
                    // NoEncontrado = FALSO;
                    break;
                case 2:
                    // clave(y) < ItemIz.clave(p)
                    insert_rec(val, node->getLeft());
                    break;
                case 3:
                    // ItemIz.clave(p) < clave(y) < ItemMe.clave(p)
                    insert_rec(val, node->getMiddle());
                    break;
                case 4:
                    // ItemMe.clave(p) < clave(y) < ItemDe.clave(p)
                    insert_rec(val, node->getRight());
                    break;
                case 5:
                    // clave(y) > ItemDe.clave(p)
                    // Insertar en el nodo de 2 claves y dividir
                    splitNode(node, val);
                    break;
            }
        } else {
            // Nodo de 3 claves
            // Implementa lógica similar a Nodo de 2 claves pero considerando 3 claves
            // Puedes llamar a splitNode cuando sea necesario
        }
    }
}

void tt::insert(int val) {
    insert_rec(val, root);
}

// Implementa otras funciones según sea necesario...

}  // namespace trees
