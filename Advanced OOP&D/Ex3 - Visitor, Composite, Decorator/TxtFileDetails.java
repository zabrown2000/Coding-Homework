public class TxtFileDetails extends FileDetails {
    private int words;
    private int size;
    public TxtFileDetails(String path, String fileName, int words, int size){
        super(path,fileName);
        this.words=words;
        this.size=size;
    }
    public int getWords() {
        return words;
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
