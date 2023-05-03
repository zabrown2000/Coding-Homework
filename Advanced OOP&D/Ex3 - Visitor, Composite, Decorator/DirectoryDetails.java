import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
public class DirectoryDetails extends FileDetails implements Iterable<FileDetails> {

    List<FileDetails> children; //pointer back to component

    public DirectoryDetails(String path, String name) {
        super(path, name);
        children = new ArrayList<>();
    }

    public void addFile(FileDetails fileDetails) {
        children.add(fileDetails);
    }

    /**
     *
     * @param visitor the visitor to accept.
     * @return result of accept
     */
    @Override
    public int accept(FileVisitor visitor) {
        return visitor.visit(this);
    }

    @Override
    public Iterator<FileDetails> iterator() {
        return children.iterator();
    } //making DirectoryDetails iterable
}