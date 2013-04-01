package hxDragonBones.objects;
import nme.utils.ByteArray;

/**
 * @author SlavaRa
 */
class DecompressedData{

	public function new(skeletonXML:Xml, textureAtlasXML:Xml, textureBytes:ByteArray) {
		this.skeletonXML = skeletonXML;
		this.textureAtlasXML = textureAtlasXML;
		this.textureBytes = textureBytes;
	}
	
	public var skeletonXML:Xml;
	public var textureAtlasXML:Xml;
	public var textureBytes:ByteArray;
	
	public function dispose() {
		skeletonXML = null;
		textureAtlasXML = null;
		textureBytes = null;
	}
}