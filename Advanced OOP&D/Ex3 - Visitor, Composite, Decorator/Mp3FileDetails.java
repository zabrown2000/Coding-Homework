public class Mp3FileDetails extends FileDetails {
    private int lengthSec;
    private int size;
    public Mp3FileDetails(String path, String fileName, int lengthSec, int size){
        super(path,fileName);
        this.lengthSec=lengthSec;
        this.size=size;
    }

    public int getLengthSec() {
        return lengthSec;
    }

    public int getSize() {
        return size;
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
}
