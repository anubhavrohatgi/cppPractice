#include <iostream>
#include <vector>



struct TreeItem
{
    std::string value;
    TreeItem* parent;
    TreeItem* firstchild;
    TreeItem* next_sibling;

    TreeItem( ) :
        parent( nullptr ),
        firstchild( nullptr ),
        next_sibling( nullptr )
    {

    }

    TreeItem( const std::string &value, TreeItem *parent ) :
        value( value ),
        parent( parent ),
        firstchild( nullptr ),
        next_sibling( nullptr )
    {

    }

    TreeItem* lastChild()
    {
        TreeItem *nextChild = firstchild, *child = nullptr;

        while( nextChild != nullptr )
        {
            child = nextChild;
            nextChild = nextChild->next_sibling;
        }

        return child;
    }

    TreeItem* find( const std::string &entry )
    {
        TreeItem *tmp = firstchild;

        while( tmp != nullptr && tmp->value != entry )
            tmp = tmp->next_sibling;

        return tmp;
    }

    void add( const std::string &value )
    {
        if( firstchild == nullptr )
            firstchild = new TreeItem( value, this );
        else
            lastChild( )->next_sibling = new TreeItem( value, this );
    }
};

bool add( const std::string &path, TreeItem *currentFolder )
{
    std::string nextFolder;
    size_t pos = path.find( '/' );

    nextFolder = ( pos != std::string::npos ) ? path.substr( 0, pos ) : "";

    if( nextFolder.length( ) > 0 )
    {
        TreeItem *findedEntry;
        findedEntry = currentFolder->find( nextFolder );

        if( findedEntry == nullptr )
            return false;

        add( path.substr( pos + 1 ), findedEntry );
    }
    else
    {
        if( currentFolder->find( path ) != nullptr )
            return false;

        currentFolder->add( path );

    }

    return true;
}

int main( void )
{
    TreeItem root;

    add( "folder1", &root );
    add( "folder1/folder2_1", &root );
    add( "folder1/folder2_2", &root );
    add( "folder1/folder2_4", &root );
    add( "folder1/folder2_2/file.txt", &root );
    add( "folder1/folder2_4", &root );

    return 0;
}
