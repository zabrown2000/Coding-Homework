public class FileShortRepVisitor implements FileVisitor{
//calling getName for each file type

    @Override
    public int visit(JpgFileDetails jpgFile) {
        System.out.println(jpgFile.getName());
        return 0;
    }
    @Override
    public int visit(Mp3FileDetails mp3File) {
        System.out.println(mp3File.getName());
        return 0;
    }
    @Override
    public int visit(PptxFileDetails pptxFile) {
        System.out.println(pptxFile.getName());
        return 0;
    }
    @Override
    public int visit(TxtFileDetails txtFile) {
        System.out.println(txtFile.getName());
        return 0;
    }
    @Override
    public int visit(DocxFileDetails docxFile) {
        System.out.println(docxFile.getName());
        return 0;
    }
    @Override
    public int visit(DirectoryDetails directory) {
        for (FileDetails file : directory) {
            file.accept(this); //going down tree calling accept on each directory until reach leaf->file
        }
        System.out.println(directory.getName()); //post order traversal
        return 0;
    }
    @Override
    public int visit(HtmlFileDetails htmlFile) {
        System.out.println(htmlFile.getName());
        return 0;
    }
}
