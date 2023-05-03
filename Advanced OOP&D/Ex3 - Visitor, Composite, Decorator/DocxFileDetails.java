public class DocxFileDetails extends FileDetails {
    private int words;
    private int pages;
    private int size;
    public DocxFileDetails(String path, String fileName, int words, int pages, int size){
        super(path, fileName);
        this.words=words;
        this.pages=pages;
        this.size=size;
     }

    public int getWords() {
        return words;
    }

    public int getPages() {
        return pages;
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
