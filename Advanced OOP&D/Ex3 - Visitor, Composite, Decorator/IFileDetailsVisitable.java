public interface IFileDetailsVisitable {
    /**
     * Accepts a visitor and returns the result of the visit.
     * @param visitor the visitor to accept.
     * @return the result of the visit. (in cases without a result, 0/1 is returned).
     */
    public int accept(FileVisitor visitor);
}
