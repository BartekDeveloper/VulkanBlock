DOXY_EXEC_PATH = X:/Pro/GameDev/VulkanBlock/docs
DOXYFILE = X:/Pro/GameDev/VulkanBlock/docs/doxyfile
DOXYDOCS_PM = X:/Pro/GameDev/VulkanBlock/docs/perlmod/DoxyDocs.pm
DOXYSTRUCTURE_PM = X:/Pro/GameDev/VulkanBlock/docs/perlmod/DoxyStructure.pm
DOXYRULES = X:/Pro/GameDev/VulkanBlock/docs/perlmod/doxyrules.make

.PHONY: clean-perlmod
clean-perlmod::
	rm -f $(DOXYSTRUCTURE_PM) \
	$(DOXYDOCS_PM)

$(DOXYRULES) \
$(DOXYMAKEFILE) \
$(DOXYSTRUCTURE_PM) \
$(DOXYDOCS_PM): \
	$(DOXYFILE)
	cd $(DOXY_EXEC_PATH) ; doxygen "$<"
